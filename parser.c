#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "stringUtils.h"
#include "parser.h"
#include "fileWriter.h"

#define INVALID_ADDRESS 65536

int _valid_address(unsigned int address, filewriter_t *file) {
    if (address >= 0 && address < INVALID_ADDRESS) {
        return 0;
    }
    filewriter_write_char(file, "Direccion invalida: ", 0);
    filewriter_write_int(file, address, 1);
    return -1;
}

int _valid_value(unsigned int value, filewriter_t *file) {
    if (value >= 0 && value < 256) {
        return 0;
    }
    filewriter_write_char(file, "Valor invalido: ", 0);
    filewriter_write_int(file, value, 1);
    return -1;
}

int _parse_value(char **split_line, int array_size, unsigned char* value, filewriter_t *file){
    if(array_size > 2) {
        unsigned int value_aux = atoi(split_line[2]);
        if (_valid_value(value_aux, file) == 0) {
            *value = (unsigned  char) value_aux;
            return 0;
        }
    }
    return -1;
}

int _parse_address(char **split_line, int array_size, unsigned int* address, filewriter_t *file) {
    if (array_size > 1) {
        char *address_line = split_line[1];
        if (split_line[0][0] == 'W') {
            strncpy(address_line, split_line[1], strlen(split_line[1]) - 1);
        }
        int address_aux = atoi(address_line);
        if (_valid_address(address_aux, file) == 0) {
            *address = (unsigned int) address_aux;
            return 0;
        }
    }
    return -1;
}

int parse_line(command_t *command, char *line, filewriter_t *file){
    int size;
    int result = 0;

    char **split_line = split(line, ' ', &size);
    char option = split_line[0][0];

    command->operation = option;

    switch (option) {
        case 'R':
            if (_parse_address(split_line, size, &command->address, file) != 0) {
                result = -1;
            }
            break;
        case 'W':
            if (_parse_address(split_line, size, &command->address, file) != 0
            || _parse_value(split_line, size, &command->value, file) != 0) {
                result = -1;
            }
            break;
        case 'M':
            break;
        case 'i':
            break;
        default:
            result = -1;
            break;
    }
    split_free(split_line);
    return result;
}


int empty_line(char *str) {
    return strcmp(str, "\n") == 0 || strcmp(str,"\r\n") == 0;
}