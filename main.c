#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <limits.h>


int main(int argc, char *argv[]) {
    int option = 0;
    int must_return = 0;
    char prefix[50] = {0};
    char *output = NULL;
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
                must_return = 1;
                break;
            case 'h':
                show_help();
                must_return = 1;
                break;
            case 'o':
                strncpy(prefix, optarg, strlen(optarg));
                break;
            case 'w':
                ways = strtol(optarg, NULL, 10);
                break;
            case 'c':
                cache_size = strtol(optarg, NULL, 10);
                must_return = 1;
                break;
            case 'b':
                block_size = strtol(optarg, NULL, 10);
                must_return = 1;
                break;
            case '?':
                must_return = 1;
                break;
            default:
                must_return = 1;
                break;
        }
    }

    if (must_return || (cache_size * 1024) < block_size ) {
       return EXIT_FAILURE;
    }

    if (output == NULL) {
        output = "stdout";
    }


    return EXIT_SUCCESS;
}