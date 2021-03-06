#include "cache.h"

cache_t cache;

int cache_create(unsigned int cache_size, unsigned int ways, unsigned int block_size) {
    cache.miss_counter = 0;
    cache.access_counter = 0;
    unsigned int blocks_number = (cache_size * KB_CONSTANT) / block_size;
    unsigned int sets_amount = blocks_number / ways;
    cache_params.block_size = block_size;
    cache_params.ways = ways;
    cache_params.sets_amount = sets_amount;

    unsigned int bits_offset = custom_log(block_size, 2);
    unsigned int bits_index = custom_log(sets_amount, 2);
    unsigned int bits_tag = SPACE_ADDRESS - bits_index - bits_offset;
    cache_params.bits_tag = bits_tag;

    cache.sets = malloc(sets_amount * sizeof(set_t));
    for (int i = 0; i < cache_params.sets_amount; ++i) {
        set_create(&cache.sets[i], i);
    }
    return 0;
}

unsigned int find_earliest(int setnum) {
    unsigned int earliest = 0;
    for (unsigned int i = 1; i < cache_params.ways; ++i) {
        earliest = cache.sets[setnum].ways[earliest].old < cache.sets[setnum].ways[i].old ? i : earliest;
    }
    return earliest;
}

char get_miss_rate() {
    if (cache.access_counter == 0) {
        return 0;
    }
    return 100 * cache.miss_counter / cache.access_counter;
}

void cache_init() {
    cache.access_counter = 0;
    cache.miss_counter = 0;
    for (int i = 0; i < cache_params.sets_amount; ++i) {
        set_init(&cache.sets[i]);
    }
}

void cache_destroy() {
    for (int i = 0; i < cache_params.sets_amount; ++i) {
        set_destroy(&cache.sets[i]);
    }
    free(cache.sets);
}

char cache_write_byte(unsigned int address, char value) {
    ++cache.access_counter;
    unsigned int set_number = find_set(address);
    if (set_write_byte(&cache.sets[set_number], address, value) != 0) {
        ++cache.miss_counter;
        return -1;
    }
    return 0;
}

char cache_read_byte(unsigned int address, char *value) {
    ++cache.access_counter;
    unsigned int set_number = find_set(address);
    if (set_read_byte(&cache.sets[set_number], address, value) != 0) {
        ++cache.miss_counter;
        cache_read_block(find_mba(address));
        set_read_byte(&cache.sets[set_number], address, value);
        return -1;
    }
    return 0;
}

void cache_read_block(int blocknum) {
    unsigned int set_num = find_set_by_blocknum(blocknum);
    unsigned int earliest = find_earliest(set_num);
    set_read_block(&cache.sets[set_num], blocknum, earliest);
}