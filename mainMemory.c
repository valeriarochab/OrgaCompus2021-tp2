#include "stdlib.h"
#include "stdio.h"
#include "mainMemory.h"
#include "cacheParams.h"
#include "addressHelper.h"

main_memory_t memory;

#define MEMORY_SIZE 65536

int main_memory_create() {
    unsigned char* mainMemory = calloc(MEMORY_SIZE, sizeof(char));
    if (mainMemory == NULL) {
        return EXIT_FAILURE;
    }
    memory.mainMemory = mainMemory;
    return EXIT_SUCCESS;
}

unsigned char main_memory_read(int address) {
    return memory.mainMemory[address];
}

void main_memory_write_toMem(unsigned char value, int address) {
    memory.mainMemory[address] = value;
}

void main_memory_destroy() {
    free(memory.mainMemory);
}