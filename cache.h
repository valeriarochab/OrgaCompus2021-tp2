#ifndef CACHE_H
#define CACHE_H

typedef struct {
    int miss;
    int last_hit;
    int access_counter;
    set_t *sets;
}cache_t;

unsigned int find_set(int address);
unsigned int find_set_by_blocknum(unsigned int blocknum);
unsigned int get_tag(unsigned int address);
unsigned int get_offset(unsigned int address);
unsigned int find_earliest(int setnum);
char get_miss_rate();

##endif