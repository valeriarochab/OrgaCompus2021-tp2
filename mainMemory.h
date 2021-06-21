#ifndef MAINMEMORY_H
#define MAINMEMORY_H

typedef struct {
    unsigned char* mainMemory;
}main_memory_t;

void write_byte_tomem(int address, char value);

int main_memory_create();

void main_memory_destroy();

#endif //MAINMEMORY_H