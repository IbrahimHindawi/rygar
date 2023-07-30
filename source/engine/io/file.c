#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "engine/utils.h"
#include "engine/types.h"
#include "engine/file.h"

ioFile io_file_read(const char *path) {
    ioFile file = { .is_valid = false };

    FILE *fp = fopen(path, "rb");
    if (ferror(fp)) {
        error_return(file, ioReadErrorGeneral, path, errno);
    }

    char *data = NULL;
    char *tmp;
    size_t used = 0;
    size_t size = 0;
    size_t n;

    while (true) {
        if (used + ioReadChunkSize + 1 > size) {
            size = used + ioReadChunkSize + 1;

            if (size <= used) {
                free(data);
                error_return(file, "Input file too large: %s\n", path);
            }

            tmp = realloc(data, size);
            if (!tmp) {
                free(data);
                error_return(file, ioReadErrorMemory, path);
            }
            data = tmp;
        }

        n = fread(data + used, 1, ioReadChunkSize, fp);
        if (n == 0)
            break;

        used += n;
    }

    if (ferror(fp)) {
        free(data);
        error_return(file, ioReadErrorGeneral, path, errno);
    }

    tmp = realloc(data, used + 1);
    if (!tmp) {
        free(data);
        error_return(file, ioReadErrorMemory, path);
    }
    data = tmp;
    data[used] = 0;

    file.data = data;
    file.len = used;
    file.is_valid = true;

    return file;
}

int io_file_write(void *buffer, size_t size, const char *file_path) {

}
