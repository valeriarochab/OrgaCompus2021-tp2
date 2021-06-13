#ifndef WAYS_H
#define WAYS_H

typedef struct {
    unsigned int valid: 1;
    unsigned int dirty: 1;
    unsigned int tag: 5;
    unsigned int old: 3;
    unsigned char* block;
}way_t;

##endif