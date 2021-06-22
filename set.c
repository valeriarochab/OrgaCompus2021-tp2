#include "set.h"

int set_create(set_t* self, int index) {
    self->index = index;
    self->ways = malloc(cache_params.ways * sizeof(way_t));
    for (int i = 0; i < cache_params.ways; ++i) {
        way_create(&self->ways[i]);
    }
    return 0;
}

void set_init(set_t *self) {
    for (int i = 0; i < cache_params.ways; ++i) {
        way_init(&self->ways[i]);
    }
}

void set_destroy(set_t* self) {
    for (int i = 0; i < cache_params.ways ; ++i) {
        way_destroy(&self->ways[i]);
    }
    free(self->ways);
}

int set_write_byte(set_t *self, int address, char value) {
    unsigned int tag = get_tag(address);
    for (int i = 0; i < cache_params.ways; ++i) {
        if (self->ways[i].valid == 1 && self->ways[i].tag == tag) {
            way_write_byte(&self->ways[i], get_offset(address), value);
            return 0;
        }
    }
    return -1;
}

int set_read_byte(set_t *self, int address, char *value) {
    unsigned int tag = get_tag(address);
    for (int i = 0; i < cache_params.ways; ++i) {
        if (self->ways[i].valid == 1 && self->ways[i].tag == tag) {
            way_read_byte(&self->ways[i], get_offset(address), value);
            return 0;
        }
    }
    return -1;
}

void set_read_block(set_t *self, int blocknum, unsigned int way) {
    for (int i = 0; i < cache_params.ways; ++i) {
        ++self->ways[i].old;
    }
    way_read_block(&self->ways[way], blocknum);
}