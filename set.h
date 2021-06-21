#ifndef SET_H
#define SET_H
#include "way.h"
#include "stdio.h"
#include "stdlib.h"
#include "cacheParams.h"
#include "addressHelper.h"


typedef struct set {
    unsigned int index;
    way_t *ways;
}set_t;

int set_create(set_t* self, int index);

void set_init(set_t* self);

void set_destroy(set_t* self);

#endif