#include "addressHelper.h"
#include "cacheParams.h"

unsigned int get_tag(unsigned int address) {
    return address >> (SPACE_ADDRESS - cache_params.bits_tag);
}

unsigned int get_offset(unsigned int address) {
    return address % cache_params.block_size;
}

unsigned int find_set(unsigned int address) {
    return find_mba(address) % cache_params.sets_amount;
}

unsigned int find_mba(unsigned int address) {
    return address / cache_params.block_size;
}

unsigned int find_set_by_blocknum(int blocknum) {
    return blocknum % cache_params.sets_amount;
}

unsigned int get_tag_by_blocknum(int blocknum) {
    return blocknum / cache_params.sets_amount;
}