#include "stdio.h"
#include "cacheParams.h"
#include "addressHelper.h"
#include "executor.h"

void init(filewriter_t *fileWriter) {
    filewriter_write_char(fileWriter, "Cache inicializada", 1);
    cache_init();
}

void executor_execute(command_t *command, filewriter_t *fileWriter) {
    char *hit = NULL;
    switch (command->operation) {
        case 'i':
            init(fileWriter);
            break;
        case 'R':
            read_byte(command->address, hit);
            break;
        case 'W':
            write_byte(command->address, command->value, hit);
            break;
        case 'M':
            filewriter_write_char(fileWriter, "Miss rate: ", 0);
            filewriter_write_float(fileWriter, get_miss_rate(), 1);
            break;
    }


    char cache_get_miss_rate() {
        return get_miss_rate();
    }
}

char read_byte(int address, char *hit) {
    return 0; //TODO
}

char write_byte(int address, char value, char *hit) {
    return 0; //TODO
}

