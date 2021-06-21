#ifndef FILEREADER_H
#define FILEREADER_H

#include <stdio.h>

typedef struct {
    FILE *fp;
}filereader_t;

void filereader_create(filereader_t* self, FILE* fp);

int filereader_next_line(filereader_t* self, char** line);

void filereader_destroy(filereader_t* self);

#endif //FILEREADER_H
