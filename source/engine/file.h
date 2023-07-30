#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *data;
    size_t len;
    bool is_valid;
} ioFile;

#define ioReadChunkSize 2097152
#define ioReadErrorGeneral "Error reading file: %s. errno: %d.\n"
#define ioReadErrorMemory "Not enough memory to read file: %s.\n"

ioFile io_file_read(const char *file_path);
int io_file_write(void *buffer, size_t size, const char *file_path);
