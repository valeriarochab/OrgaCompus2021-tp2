#ifndef WAY_H
#define WAY_H
#include "mainMemory.h"
#include "cacheParams.h"
#include "addressHelper.h"
#include "utils.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct way {
    unsigned int valid;
    unsigned int tag;
    unsigned int old;
    char* block;
}way_t;

void way_create(way_t* self);

void way_init(way_t *self);

void way_write_byte(way_t *self, unsigned int offset, char value);

void way_destroy(way_t* self);

#endif //WAY_H
