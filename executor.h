#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "mainMemory.h"
#include "fileWriter.h"
#include "command.h"
#include "cache.h"

void init(filewriter_t *fileWriter);
void executor_execute(command_t *command, filewriter_t* filewriter);
void init(filewriter_t *fileWriter);
char cache_get_miss_rate();
void write_byte_tomem(int address, char value);
char read_byte(int address, char *value, char *hit);
char write_byte(int address, char value, char *hit);

#endif //EXECUTOR_H
