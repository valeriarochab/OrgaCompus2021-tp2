#ifndef COMMAND_H
#define COMMAND_H

#include "fileWriter.h"
typedef struct {
    unsigned char operation;
    unsigned int address;
    unsigned char value;
}command_t;

int command_create(command_t* self, char* line, filewriter_t *file);

void command_destroy(command_t* self);

#endif //COMMAND_H
