#ifndef MAINMEMORY_H
#define MAINMEMORY_H

typedef struct {
    char* mainMemory;
}main_memory_t;

int main_memory_create();

void main_memory_write_toMem(char value, int address);

void main_memory_destroy();

#endif //MAINMEMORY_H
 