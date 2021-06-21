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