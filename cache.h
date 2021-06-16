#ifndef CACHE_H
#define CACHE_H
#include "set.h"

typedef struct cache {
    int miss_counter;
    int last_hit;
    int access_counter;
    set_t *sets;
}cache_t;

unsigned int find_set(int address);
unsigned int find_set_by_blocknum(unsigned int blocknum);
unsigned int get_tag(unsigned int address);
unsigned int get_offset(unsigned int address);
unsigned int find_earliest(int setnum);
void read_block(int blocknum);
char read_byte(int address, char *hit);
char write_byte(int address, char value, char *hit);
char get_miss_rate();

#endif