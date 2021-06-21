#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "fileWriter.h"

int filewriter_create(filewriter_t *self, char *file_name) {
    if (strcmp(file_name, "stdout") == 0) {
        self->file = stdout;
    } else {
        FILE *fp;
        fp = fopen(file_name, "w");
        if (fp == NULL) {
            fprintf(stderr, "File not found: %s  \n", file_name);
            return EXIT_FAILURE;
        }
        self->file = fp;
    }
    return EXIT_SUCCESS;
}

void filewriter_write_int(filewriter_t *self, unsigned int output, unsigned int end_line) {
    fprintf(self->file, "%u", output);
    if (end_line == 1) {
        fprintf(self->file, "\n");
    }
}

void filewriter_write_char(filewriter_t *self, char* output, unsigned int end_line) {
    fprintf(self->file, "%s", output);
    if (end_line == 1) {
        fprintf(self->file, "\n");
    }
}

void filewriter_write_float(filewriter_t *self, float output, unsigned int end_line) {
    fprintf(self->file, "%.3f", output);
    if (end_line == 1) {
        fprintf(self->file, "\n");
    }
}

void filewriter_destroy(filewriter_t *self) {
    if (fileno(self->file) != 1) {
        fclose(self->file);
    }
}