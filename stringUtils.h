#ifndef STRINGUTILS_H
#define STRINGUTILS_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char** split(const char* str, char sep, int * size);
void split_free(char **strv);

#endif //STRINGUTILS_H
