#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "stringUtils.h"
#include "parser.h"

int parse_line(command_t *command, char *line){
    int size;
    int result = 0;

    char **splited_line = split(line, ' ', &size);
    char option = splited_line[0][0];

    command->operation = option;

    switch (option) {
        case 'R':
        case 'W':
        case 'M':
            break;
        case 'i':
            break;
        default:
            result = -1;
            break;
    }
    split_free(splited_line);
    return result;
}

int empty_line(char *str) {
    return strcmp(str, "\n") == 0 || strcmp(str,"\r\n") == 0;
}