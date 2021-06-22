#include "stdio.h"
#include "cacheParams.h"
#include "addressHelper.h"
#include "executor.h"

void init(filewriter_t *fileWriter) {
    filewriter_write_char(fileWriter, "Cache inicializada", 1);
    cache_init();
}

void executor_execute(command_t *command, filewriter_t *fileWriter) {
    char hit = 'H';
    switch (command->operation) {
        case 'i':
            init(fileWriter);
            break;
        case 'R':
            read_byte(command->address, &hit);
            break;
        case 'W':
            write_byte(command->address, command->value, &hit);
            filewriter_write_char(fileWriter, "Se guardó el valor: ", 0);
            filewriter_write_int(fileWriter, command->value, 0);
            if (hit == 'H') {
                filewriter_write_char(fileWriter, " - La operacion fue un hit", 1);
            } else {
                filewriter_write_char(fileWriter, " - La operacion fue un miss", 1);
            }
            break;
        case 'M':
            filewriter_write_char(fileWriter, "Miss rate: ", 0);
            filewriter_write_float(fileWriter, get_miss_rate(), 1);
            break;
    } 
}

 char cache_get_miss_rate() {
    return get_miss_rate();
}

char read_byte(int address, char *hit) {
    return 0; //TODO
}

char write_byte(int address, char value, char *hit) {
    if (cache_write_byte(address, value) != 0) {
        *hit = 'M';
    }
    main_memory_write_toMem(value, address);
    return 0;
}

void write_byte_tomem(int address, char value) {
    main_memory_write_toMem(value, address);
}
