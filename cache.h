#ifndef CACHE_H
#define CACHE_H
#include "set.h"
#include "utils.h"
#include "addressHelper.h"
#include "cacheParams.h"
#include "stdio.h"
#include "stdlib.h"


typedef struct cache {
    int miss_counter;
    int last_hit;
    int access_counter;
    set_t *sets;
}cache_t;


int cache_create(unsigned int cache_size, unsigned int ways, unsigned int block_size);
void cache_init();
unsigned int find_earliest(int setnum);
void read_block(int blocknum);
char read_byte(int address, char *hit);
char write_byte(int address, char value, char *hit);
char get_miss_rate();
void cache_destroy();

#endif