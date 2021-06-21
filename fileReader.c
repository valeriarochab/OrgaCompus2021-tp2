#include <stdlib.h>
#include "fileReader.h"

void filereader_create(filereader_t *self, FILE *fp) {
    self->fp = fp;
}

int filereader_next_line(filereader_t *self, char** line) {
    size_t len = 0;
    return getline(line, &len, self->fp);
}

void filereader_destroy(filereader_t *self) {
    fclose(self->fp);
}