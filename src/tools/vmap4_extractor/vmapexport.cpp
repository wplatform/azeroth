/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "adtfile.h"
#include "Banner.h"
#include "dbcfile.h"
#include "StringFormat.h"
#include "vmapexport.h"
#include "wdtfile.h"
#include "wmo.h"
#include "mpqfile.h"
#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cerrno>
#include <sys/stat.h>

#ifdef _WIN32
    #include <direct.h>
    #define mkdir _mkdir
#endif

//------------------------------------------------------------------------------
// Defines

#define MPQ_BLOCK_SIZE 0x1000

//-----------------------------------------------------------------------------

extern ArchiveSet gOpenArchives;

uint32 CONF_TargetBuild = 18273;              // 5.4.8.18273

// List MPQ for extract maps from
char const* CONF_mpq_list[]=
{
    "world.MPQ",
    "misc.MPQ",
    "model.MPQ",
    "expansion1.MPQ",
    "expansion2.MPQ",
    "expansion3.MPQ",
    "expansion4.MPQ"
};

uint32 const builds[] = {16016, 16048, 16057, 16309, 16357, 16516, 16650, 16844, 16965, 17116, 17266, 17325, 17345, 17538, 17645, 17688, 17898, 18273};
static char const* const langs[] = {"enGB", "enUS", "deDE", "esES", "frFR", "koKR", "zhCN", "zhTW", "enCN", "enTW", "esMX", "ruRU" };
#define LANG_COUNT 12

struct map_info
{
    char name[64];
    int32 parent_id;
};


std::map<uint32, map_info> map_ids;
std::unordered_set<uint32> maps_that_are_parents;
char output_path[128]=".";
char input_path[1024]=".";
bool hasInputPathParam = false;
bool preciseVectorData = false;
std::unordered_map<std::string, WMODoodadData> WmoDoodads;

// Constants

char const* szWorkDirWmo = "./Buildings";


void LoadLocaleMPQFiles(int const locale) {

    std::string fileName = Trinity::StringFormat("%s/Data/misc.MPQ", input_path);
    auto* pArchive = new MPQArchive(fileName.c_str());

    fileName = Trinity::StringFormat("%s/Data/%s/locale-%s.MPQ", input_path, langs[locale], langs[locale]);
    pArchive->PatchArchive(fileName.c_str(), "");

    for (const auto &item : builds) {
        fileName = Trinity::StringFormat("%s/Data/%s/wow-update-%s-%u.MPQ", input_path, langs[locale], langs[locale], item);
        if (boost::filesystem::exists(fileName))
            pArchive->PatchArchive(fileName.c_str(), "");
    }
    // delete mpqArchive; destroy the object on gOpenArchives
}


void LoadCommonMPQFiles() {
    std::string fileName = Trinity::StringFormat("%s/Data/world.MPQ", input_path);
    auto* pArchive = new MPQArchive(fileName.c_str());

    int count = sizeof(CONF_mpq_list) / sizeof(char*);
    for (int i = 1; i < count; ++i) {
        fileName = Trinity::StringFormat("%s/Data/%s", input_path, CONF_mpq_list[i]);
        pArchive->PatchArchive(fileName.c_str(), "");
    }

    for (const auto &item : builds) {
        std::string fileName = Trinity::StringFormat("%s/Data/wow-update-base-%u.MPQ", input_path, item);
        if (boost::filesystem::exists(fileName))
            pArchive->PatchArchive(fileName.c_str(), "");
    }
}


inline void CloseMPQFiles() {
    for (auto &gOpenArchive : gOpenArchives) {
        gOpenArchive->close();
    }
    gOpenArchives.clear();
}

std::map<std::pair<uint32, uint16>, uint32> uniqueObjectIds;

uint32 GenerateUniqueObjectId(uint32 clientId, uint16 clientDoodadId)
{
    return uniqueObjectIds.emplace(std::make_pair(clientId, clientDoodadId), uniqueObjectIds.size() + 1).first->second;
}

// Local testing functions

bool FileExists(char const* file)
{
    if (FILE* n = fopen(file, "rb"))
    {
        fclose(n);
        return true;
    }
    return false;
}

void strToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        ++str;
    }
}

bool ExtractSingleWmo(std::string& fname)
{
    // Copy files from archive
    std::string originalName = fname;

    char szLocalFile[1024];
    char* plain_name = GetPlainName(&fname[0]);
    FixNameCase(plain_name, strlen(plain_name));
    FixNameSpaces(plain_name, strlen(plain_name));
    sprintf(szLocalFile, "%s/%s", szWorkDirWmo, plain_name);

    if (FileExists(szLocalFile))
        return true;

    int p = 0;
    // Select root wmo files
    char const* rchr = strrchr(plain_name, '_');
    if (rchr != nullptr)
    {
        char cpy[4];
        memcpy(cpy, rchr, 4);
        for (int i = 0; i < 4; ++i)
        {
            int m = cpy[i];
            if (isdigit(m))
                p++;
        }
    }

    if (p == 3)
        return true;

    bool file_ok = true;
    WMORoot froot(originalName);
    if (!froot.open())
    {
        printf("Couldn't open RootWmo!!!\n");
        return true;
    }
    FILE *output = fopen(szLocalFile,"wb");
    if(!output)
    {
        printf("couldn't open %s for writing!\n", szLocalFile);
        return false;
    }
    froot.ConvertToVMAPRootWmo(output);
    WMODoodadData& doodads = WmoDoodads[plain_name];
    std::swap(doodads, froot.DoodadData);
    int Wmo_nVertices = 0;
    uint32 groupCount = 0;
    //printf("root has %d groups\n", froot->nGroups);
    if (froot.nGroups !=0)
    {
        for (uint32 i = 0; i < froot.nGroups; ++i)
        {
            char temp[1024];
            strncpy(temp, fname.c_str(), 1024);
            temp[fname.length()-4] = 0;

            WMOGroup fgroup(Trinity::StringFormat("%s_%03u.wmo", temp, i));
            if (!fgroup.open(&froot))
            {
                printf("Could not open all Group file for: %s\n", plain_name);
                file_ok = false;
                break;
            }

            if (fgroup.ShouldSkip(&froot))
                continue;

            Wmo_nVertices += fgroup.ConvertToVMAPGroupWmo(output, preciseVectorData);
            ++groupCount;
            for (uint16 groupReference : fgroup.DoodadReferences)
            {
                if (groupReference >= doodads.Spawns.size())
                    continue;

                uint32 doodadNameIndex = doodads.Spawns[groupReference].NameIndex;
                if (froot.ValidDoodadNames.find(doodadNameIndex) == froot.ValidDoodadNames.end())
                    continue;

                doodads.References.insert(groupReference);
            }
        }
    }

    fseek(output, 8, SEEK_SET); // store the correct no of vertices
    fwrite(&Wmo_nVertices, sizeof(int), 1, output);
    // store the correct no of groups
    fwrite(&groupCount, sizeof(uint32), 1, output);
    fclose(output);

    // Delete the extracted file in the case of an error
    if (!file_ok)
        remove(szLocalFile);
    return true;
}

void ParsMapFiles()
{
    std::unordered_map<uint32, WDTFile> wdts;
    auto getWDT = [&wdts](uint32 mapId) -> WDTFile*
    {
        auto itr = wdts.find(mapId);
        if (itr == wdts.end())
        {
            char fn[512];
            char* name = map_ids[mapId].name;
            sprintf(fn, "World\\Maps\\%s\\%s.wdt", name, name);
            itr = wdts.emplace(std::piecewise_construct, std::forward_as_tuple(mapId), std::forward_as_tuple(fn, name, maps_that_are_parents.count(mapId) > 0)).first;
            if (!itr->second.init(mapId))
            {
                wdts.erase(itr);
                return nullptr;
            }
        }

        return &itr->second;
    };

    for (auto itr = map_ids.begin(); itr != map_ids.end(); ++itr)
    {
        if (WDTFile* WDT = getWDT(itr->first))
        {
            WDTFile* parentWDT = itr->second.parent_id >= 0 ? getWDT(itr->second.parent_id) : nullptr;
            printf("Processing Map %u\n[", itr->first);
            for (int32 x = 0; x < 64; ++x)
            {
                for (int32 y = 0; y < 64; ++y)
                {
                    bool success = false;
                    if (ADTFile* ADT = WDT->GetMap(x, y))
                    {
                        success = ADT->init(itr->first, itr->first);
                        WDT->FreeADT(ADT);
                    }
                    if (!success && parentWDT)
                    {
                        if (ADTFile* ADT = parentWDT->GetMap(x, y))
                        {
                            ADT->init(itr->first, itr->second.parent_id);
                            parentWDT->FreeADT(ADT);
                        }
                    }
                }
                printf("#");
                fflush(stdout);
            }
            printf("]\n");
        }
    }
}

void getGamePath()
{
#ifdef _WIN32
    strcpy(input_path,"Data\\");
#else
    strcpy(input_path,"Data/");
#endif
}

bool processArgv(int argc, char ** argv, const char *versionString)
{
    bool result = true;
    hasInputPathParam = false;
    preciseVectorData = false;

    for(int i = 1; i < argc; ++i)
    {
        if(strcmp("-s",argv[i]) == 0)
        {
            preciseVectorData = false;
        }
        else if(strcmp("-d",argv[i]) == 0)
        {
            if((i+1)<argc)
            {
                hasInputPathParam = true;
                strncpy(input_path, argv[i + 1], sizeof(input_path));
                input_path[sizeof(input_path) - 1] = '\0';

                if (input_path[strlen(input_path) - 1] != '\\' && input_path[strlen(input_path) - 1] != '/')
                    strcat(input_path, "/");
                ++i;
            }
            else
            {
                result = false;
            }
        }
        else if(strcmp("-?",argv[1]) == 0)
        {
            result = false;
        }
        else if(strcmp("-l",argv[i]) == 0)
        {
            preciseVectorData = true;
        }
        else
        {
            result = false;
            break;
        }
    }
    if(!result)
    {
        printf("Extract %s.\n",versionString);
        printf("%s [-?][-s][-l][-d <path>]\n", argv[0]);
        printf("   -s : (default) small size (data size optimization), ~500MB less vmap data.\n");
        printf("   -l : large size, ~500MB more vmap data. (might contain more details)\n");
        printf("   -d <path>: Path to the vector data source folder.\n");
        printf("   -? : This message.\n");
    }
    return result;
}


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// Main
//
// The program must be run with two command line arguments
//
// Arg1 - The source MPQ name (for testing reading and file find)
// Arg2 - Listfile name
//

int main(int argc, char ** argv)
{
    Trinity::Banner::Show("VMAP data extractor", [](char const* text) { printf("%s\n", text); }, nullptr);

    bool success = true;
    const char *versionString = "V5.4.8 2022_10";

    // Use command line arguments, when some
    if (!processArgv(argc, argv, versionString))
        return 1;

    // some simple check if working dir is dirty
    else
    {
        std::string sdir = std::string(szWorkDirWmo) + "/dir";
        std::string sdir_bin = std::string(szWorkDirWmo) + "/dir_bin";
        struct stat status;
        if (!stat(sdir.c_str(), &status) || !stat(sdir_bin.c_str(), &status))
        {
            printf("Your output directory seems to be polluted, please use an empty directory!\n");
            printf("<press return to exit>");
            char garbage[2];
            return scanf("%c", garbage);
        }
    }

    printf("Extract %s. Beginning work ....\n", versionString);
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Create the working directory
    if (mkdir(szWorkDirWmo
#if defined(__linux__) || defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
                    , 0711
#endif
                    ))
            success = (errno == EEXIST);

    LoadCommonMPQFiles();
    std::string in_path(input_path);
    for (int i = 0; i < LANG_COUNT; i++) {
        std::string localePath = Trinity::StringFormat("%s/Data/%s", in_path, langs[i]);
        if (!boost::filesystem::exists(localePath)) {
            continue;
        }
        printf("Detected and using locale: %s\n", langs[i]);
        LoadLocaleMPQFiles(i);
        break;
    }

    // Extract models, listed in GameObjectDisplayInfo.dbc
    ExtractGameobjectModels();

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if (success)
    {
        DBCFile dbc("DBFilesClient\\Map.dbc");
        if (!dbc.open())
        {
            printf("FATAL ERROR: Map.dbc not found in data file.\n");
            exit(1);
        }

        for (uint32 x = 0; x < dbc.getRecordCount(); ++x)
        {
            DBCFile::Record record = dbc.getRecord(x);
            map_info& m = map_ids[record.getUInt(0)];

            char const* map_name = record.getString(1);
            size_t max_map_name_length = sizeof(m.name);
            if (strlen(map_name) >= max_map_name_length)
            {
                printf("Fatal error: Map name too long!\n");
                exit(1);
            }

            strncpy(m.name, map_name, max_map_name_length);
            m.name[max_map_name_length - 1] = '\0';
            m.parent_id = int16(record.getInt(18));
            if (m.parent_id >= 0)
                maps_that_are_parents.insert(m.parent_id);

            printf("Map - %s\n", m.name);
        }

        ParsMapFiles();
    }
    printf("\n");
    CloseMPQFiles();
    if (!success)
    {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n", versionString, preciseVectorData);
        getchar();
    }

    printf("Extract %s. Work complete. No errors.\n", versionString);
    return 0;
}
