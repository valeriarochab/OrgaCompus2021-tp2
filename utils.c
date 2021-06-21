#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"

#define VERSION "0.0.1"

void show_version() {
    printf("TP2 Version: %s\n", VERSION);
}

void show_error(char *msg) {
    fprintf(stderr, "%s\n", msg);
}

void show_help() {
    printf("Usage:\n");
    printf("\ttp2 -h\n");
    printf("\ttp2 -V\n");
    printf("\ttp2 options archivo\n");
    printf("Options\n");
    printf("\t-h, --help\tImprime ayuda.\n");
    printf("\t-V, --version\tVersión del programa.\n");
    printf("\t-o, \tArchivo de salida.\n");
    printf("\t-w, --ways\tCantidad de vı́as.\n");
    printf("\t-c, --cachesize\tTamaño del caché en kilobytes.\n");
    printf("\t-bs, --blocksize\tTamaño de bloque en bytes.\n");

    printf("Examples\n");
    printf("\n");
    printf("\ttp2 -w 4 -cs 8 -bs 16 prueba1.mem\n");
}

int is_valid_file(FILE *fp) {
    int size = 0;
    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        rewind(fp);
    }
    return size;
}

unsigned int custom_log(unsigned int x, int base) {
    return log(x) / log(base);
}