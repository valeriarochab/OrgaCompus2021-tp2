#ifndef MAINMEMORY_H
#define MAINMEMORY_H

typedef struct {
    unsigned char* mainMemory;
}main_memory_t;

int main_memory_create();

unsigned char main_memory_read(int address);

void main_memory_write_toMem(unsigned char value, int address);

void main_memory_destroy();

#endif //MAINMEMORY_H
 