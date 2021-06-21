#include "command.h"
#include "parser.h"

int command_create(command_t* self, char* line){
    return parse_line(self, line);
}

void command_destroy(command_t* self){

}