#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <limits.h>
#include "fileReader.h"
#include "fileWriter.h"
#include "mainMemory.h"
#include "cache.h"
#include "parser.h"
#include "executor.h"
#include "utils.h"


int create_success(unsigned int cache_size, unsigned int ways, unsigned int block_size){
    if (main_memory_create() == EXIT_FAILURE || cache_create(cache_size, ways, block_size) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    int option = 0;
    int must_return = 0;
    char prefix[50] = {0};
    char *output_option = NULL;
    unsigned int ways;
    unsigned int cache_size;
    unsigned int block_size;

    static struct option long_options[] = {
        {"version", no_argument, 0, 'V'},
        {"help", no_argument, 0, 'h'},
        {"output", required_argument, 0, 'o'},
        {"ways", required_argument, 0, 'w'},
        {"cachesize", required_argument, 0, 'c'},
        {"blocksize", required_argument, 0, 'b'},
    };

    int long_index = 0;
    while ((option = getopt_long(argc, argv, "Vho:w:c:b:", long_options, &long_index)) != -1) {
        if (must_return) {
            show_error("Parametros invalidos");
            return 1;
        }

        switch (option) {
            case 'V':
                show_version();
                return EXIT_SUCCESS;
                break;
            case 'h':
                show_help();
                return EXIT_SUCCESS;
                break;
            case 'o':
                strncpy(prefix, optarg, strlen(optarg));
                break;
            case 'w':
                ways = strtol(optarg, NULL, 10);
                break;
            case 'c':
                cache_size = strtol(optarg, NULL, 10);
                break;
            case 'b':
                block_size = strtol(optarg, NULL, 10);
                break;
            case '?':
                must_return = 1;
                break;
            default:
                must_return = 1;
                break;
        }
    }

    if (must_return || (optind + 1 != argc) || (cache_size * 1024) < block_size ) {
       return EXIT_FAILURE;
    }

    if (output_option == NULL) {
        output_option = "stdout";
    }

    if (create_success(cache_size, ways, block_size) != 0) {
        return EXIT_FAILURE;
    }

    filewriter_t output_file;
    filewriter_create(&output_file, output_option);
    FILE *fp;
    fp = fopen(argv[optind++], "r");
    if (fp == NULL)
        return EXIT_FAILURE;

    filereader_t file;
    filereader_create(&file, fp);

    char *line = NULL;
    while (filereader_next_line(&file, &line) != -1) {
        if(empty_line(line) == 1) {
            continue;
        }
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        filewriter_write_char(&output_file, "Comando leído: ", 0);
        filewriter_write_char(&output_file, line, 1);

        command_t command;
        if (command_create(&command, line) != 0) {
            filewriter_write_char(&output_file, "Comando inválido.", 1);
            continue;
        }
        executor_execute(&command, &output_file);
        command_destroy(&command);
    }
    filereader_destroy(&file);
    cache_destroy();
    main_memory_destroy();
    
    return EXIT_SUCCESS;
}
