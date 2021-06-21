#ifndef COMMAND_H
#define COMMAND_H
typedef struct {
    unsigned char operation;
    unsigned int address;
    unsigned char value;
}command_t;

int command_create(command_t* self, char* line);

void command_destroy(command_t* self);

#endif //COMMAND_H
