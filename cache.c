#include "cacheParams.h"

unsigned int find_set(int address) {
    unsigned int mba = address / cache_params.block_size;
    return mba % cache_params.sets_amount;
}

unsigned int find_set_by_blocknum(unsigned int blocknum){
    return blocknum / cache_params.sets_amount;
}

unsigned int get_tag(unsigned int address) {
    return address >> (16 - cache_params.bits_tag);
}

unsigned int get_offset(unsigned int address) {
    return address % cache_params.block_size;
}

char get_miss_rate(){
    if (cache.access_counter == 0) {
        return "0";
    }
    return (char) cache.miss_counter / cache.access_counter;
}
