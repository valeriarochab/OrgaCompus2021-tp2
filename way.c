#include "way.h"

void way_create(way_t *self) {
    self->valid = 0;
    self->tag = 0;
    self->old = 0;
    self->block = malloc(cache_params.block_size * sizeof(unsigned char));
}

void way_init(way_t *self) {
    for (int i = 0; i < cache_params.block_size; ++i) {
        self->block[i] = 0;
    }
    self->valid = 0;
    self->tag = 0;
    self->old = 0;
}

void way_destroy(way_t *self) {
    free(self->block);
}
