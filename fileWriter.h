#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <stdio.h>

typedef struct {
   FILE* file;
}filewriter_t;

int filewriter_create(filewriter_t* self, char *filename);

void filewriter_write_int(filewriter_t *self, unsigned int output, unsigned int end_line);

void filewriter_write_char(filewriter_t *self, char* output, unsigned int end_line);

void filewriter_write_float(filewriter_t *self, float output, unsigned int end_line);

void filewriter_destroy(filewriter_t* self);

#endif //FILEWRITER_H