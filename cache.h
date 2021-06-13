#ifndef CACHE_H
#define CACHE_H

typedef struct {
    int miss;
    int last_hit;
    int access_counter;
    set_t *sets;
}cache_t;

##endif