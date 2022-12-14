#define _CRT_SECURE_NO_DEPRECATE
#ifndef _CRT_SECURE_NO_WARNINGS // fuck the police^Wwarnings
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef MPQ_H
#define MPQ_H

#include <string.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <deque>
#include "StormLib.h"
#include "Define.h"

#ifdef _WIN32
#include <Windows.h>    // mainly only HANDLE definition is required
#endif

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
