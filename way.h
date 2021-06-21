#ifndef WAY_H
#define WAY_H
#include "mainMemory.h"
#include "cacheParams.h"
#include "addressHelper.h"
#include "utils.h"
#include "stdio.h"
#include "stdlib.h"

typedef struct way {
    unsigned int valid: 1;
    unsigned int tag: 5;
    unsigned int old: 3;
    unsigned char* block;
}way_t;

void way_create(way_t* self);

void way_init(way_t *self);

void way_destroy(way_t* self);

#endif //WAY_H
