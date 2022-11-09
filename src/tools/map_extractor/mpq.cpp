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

#include "mpq.h"
#include "StormLib.h"
#include <cstdio>
#include <algorithm>

ArchiveSet gOpenArchives;

MPQArchive::MPQArchive(char const *filename) : mpq_a(nullptr) {

    printf("Opening %s\n", filename);
    if (!SFileOpenArchive(filename, 0, MPQ_OPEN_READ_ONLY, &mpq_a)) {
        logErrorMessage(filename);
        return;
    }
    gOpenArchives.push_front(this);
}

void MPQArchive::close() {
    SFileCloseArchive(mpq_a);
}

bool MPQArchive::PatchArchive(const char *filename, const char *prefix) const {
    printf("Opening %s\n", filename);
    if (!SFileOpenPatchArchive(mpq_a, filename, prefix, 0)) {
        logErrorMessage(filename);
        return false;
    }
    return true;
}

void MPQArchive::logErrorMessage(const char *filename) {
    switch (GetLastError()) {
        case ERROR_PATH_NOT_FOUND :
            printf("Error opening archive '%s': Does file really exist?\n", filename);
            break;
        case ERROR_BAD_FORMAT :            /* bad file format */
            printf("Error opening archive '%s': Bad file format\n", filename);
            break;
        case ERROR_SEEK :         /* seeking in file failed */
            printf("Error opening archive '%s': Seeking in file failed\n", filename);
            break;
        case ERROR_READ_FAULT :              /* Read error in archive */
            printf("Error opening archive '%s': Read error in archive\n", filename);
            break;
        case ERROR_OUTOFMEMORY :               /* maybe not enough memory? :) */
            printf("Error opening archive '%s': Maybe not enough memory\n", filename);
            break;
        default:
            printf("Error opening archive '%s': Unknown error\n", filename);
            break;
    }
}

MPQFile::MPQFile(char const *filename) :
        eof(false),
        buffer(0),
        pointer(0),
        size(0) {
    for (auto &gOpenArchive : gOpenArchives) {
        HANDLE mpqFile;
        if (!SFileOpenFileEx(gOpenArchive->mpq_a, filename, SFILE_OPEN_FROM_MPQ, &mpqFile)) {
            continue;
        }
        size = SFileGetFileSize(mpqFile, nullptr);
        if (size <= 1) {
            printf("Can't open %s, size = %lu!\n", filename, size);
            SFileCloseFile(mpqFile);
            eof = true;
            return;
        }
        // Read the file from the archive
        DWORD read = 0;
        buffer = new char[size];
        if (!SFileReadFile(mpqFile, buffer, size, &read, nullptr) || size != read) {
            printf("Can't read %s, size=%lu read=%lu!\n", filename, size, read);
            SFileCloseFile(mpqFile);
            eof = true;
            return;
        }
        SFileCloseFile(mpqFile);
        return;

    }
    eof = true;
    buffer = nullptr;
}

size_t MPQFile::read(void *dest, size_t bytes) {
    if (eof) return 0;

    size_t rpos = pointer + bytes;
    if (rpos > size_t(size)) {
        bytes = size - pointer;
        eof = true;
    }

    memcpy(dest, &(buffer[pointer]), bytes);

    pointer = rpos;

    return bytes;
}

void MPQFile::seek(int offset) {
    pointer = offset;
    eof = (pointer >= size);
}

void MPQFile::seekRelative(int offset) {
    pointer += offset;
    eof = (pointer >= size);
}

void MPQFile::close() {
    delete[] buffer;
    buffer = 0;
    eof = true;
}
