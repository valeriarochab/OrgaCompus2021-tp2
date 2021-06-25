#ifndef PARSER_H
#define PARSER_H

#include "command.h"

int parse_line(command_t *command, char *line, filewriter_t *file);
int empty_line(char *str);

#endif //PARSER_H
