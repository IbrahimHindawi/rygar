#pragma once

#include <stdio.h>

#define error_exit(...) { \
    fprintf(stderr, __VA_ARGS__); \
}

#define error_return(r, ...) { \
    fprintf(stderr, __VA_ARGS__); \
    return r; \
}
