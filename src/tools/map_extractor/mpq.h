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

#ifndef MPQ_H
#define MPQ_H

#include "loadlib/loadlib.h"
#include "StormLib.h"

#include <string.h>
#include <string>
#include <vector>
#include <deque>

class MPQArchive {

public:
    HANDLE mpq_a;
    MPQArchive(char const *filename);
    ~MPQArchive() { close(); }
    bool PatchArchive(const char *filename, const char *lang) const;
    void close();

    void GetFileListTo(std::vector<std::string> &fileList) const {
        SFILE_FIND_DATA foundFile;
        HANDLE listFile = SFileFindFirstFile(mpq_a, "DBFilesClient\\*", &foundFile, NULL);
        if (listFile) {
            do {
                fileList.emplace_back(foundFile.cFileName);
            } while (SFileFindNextFile(listFile, &foundFile));
            SFileFindClose(listFile);
        }
    }

private:
    static void logErrorMessage(const char *filename) ;
};

typedef std::deque<MPQArchive *> ArchiveSet;

class MPQFile {
    //MPQHANDLE handle;
    bool eof;
    char *buffer;
    DWORD pointer, size;

    MPQFile(MPQFile const & /*f*/) = delete;

    void operator=(MPQFile const & /*f*/) = delete;

public:
    MPQFile(char const *filename);    // filenames are not case sensitive
    ~MPQFile() { close(); }

    size_t read(void *dest, size_t bytes);

    size_t getSize() { return size; }

    size_t getPos() { return pointer; }

    char *getBuffer() { return buffer; }

    char *getPointer() { return buffer + pointer; }

    bool isEof() { return eof; }

    void seek(int offset);

    void seekRelative(int offset);

    void close();
};

inline void flipcc(char *fcc) {
    std::swap(fcc[0], fcc[3]);
    std::swap(fcc[1], fcc[2]);
}

#endif
