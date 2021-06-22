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

void way_read_block(way_t *self, int blocknum) {
    self->valid = 1;
    self->tag = get_tag_by_blocknum(blocknum);
    self->old = 0;

    for (int i = 0; i < cache_params.block_size; ++i) {
        self->block[i] = main_memory_read(blocknum * cache_params.block_size + i);
    }
}

void way_read_byte(way_t *self, unsigned int offset, char *value) {
    *value = self->block[offset];
}

void way_write_byte(way_t *self, unsigned int offset, char value) {
    self->block[offset] = value;
}

void way_destroy(way_t *self) {
    free(self->block);
}
