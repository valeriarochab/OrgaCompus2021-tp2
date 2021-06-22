#ifndef CACHE_PARAMS_H
#define CACHE_PARAMS_H

#define SPACE_ADDRESS 16
#define KB_CONSTANT 1024

typedef struct {
    int sets_amount;
    int block_size;
    int ways;
    unsigned int bits_tag;
} cache_params_t;

cache_params_t cache_params;

#endif //CACHE_PARAMS_H