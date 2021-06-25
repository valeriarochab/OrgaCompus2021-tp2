#include "command.h"
#include "parser.h"

int command_create(command_t* self, char* line, filewriter_t *file){
    return parse_line(self, line, file);
}

void command_destroy(command_t* self){

}
