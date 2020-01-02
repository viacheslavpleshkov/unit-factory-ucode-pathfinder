#include "pathfinder.h"

void *mx_until_memalloc(size_t size) {
    void *ptr;

    if ((ptr = malloc(size)))
        mx_until_bzero(ptr, size);
    return (ptr);
}
