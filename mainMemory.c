#include "stdlib.h"
#include "stdio.h"
#include "mainMemory.h"
#include "cacheParams.h"
#include "addressHelper.h"

main_memory_t memory;

#define MEMORY_SIZE 65536

int main_memory_create() {
    unsigned char* memory_table = calloc(MEMORY_SIZE, sizeof(unsigned char));
    if (memory_table == NULL) {
        return -1;
    }
    memory.mainMemory = memory_table;
    return 0;
}

void main_memory_destroy() {
    free(memory.mainMemory);
}