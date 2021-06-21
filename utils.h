#ifndef UTILS_H
#define UTILS_H
#include "stdio.h"

void show_version();

void show_error(char *msg);

void show_help();

int is_valid_file(FILE *fp);

unsigned int custom_log(unsigned int x, int base);

#endif //UTILS_H