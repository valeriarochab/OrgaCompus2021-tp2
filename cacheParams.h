#ifndef CACHE_PARAMS_H
#define CACHE_PARAMS_H

typedef struct {
    int sets_amount;
    int block_size;
    int ways;
    unsigned int bits_tag;
} cache_params_t;

cache_params_t cache_params;

#endif //CACHE_PARAMS_H