#include "stringUtils.h"

char* add_string(const char* str, size_t indice){
    char* str_aux = malloc(indice + 1);
    if (!str_aux) {
        return NULL;
    }
    strncpy(str_aux, str, indice);
    str_aux[indice] = '\0';
    return str_aux;
}

char** split(const char* str, char sep, int* size){
    char* vector[strlen(str)];
    char *pal_aux = strchr(str, sep);
    size_t i = 0;
    while (pal_aux != NULL) {
        vector[i] = add_string(str, strlen(str) - strlen(pal_aux));
        str = pal_aux + 1;
        pal_aux = strchr(str, sep);
        i++;
    }
    vector[i] = add_string(str, strlen(str));
    i++;
    vector[i] = NULL;

    char **strv = malloc((i + 1) * sizeof(char*));
    if (!strv) {
        return NULL;
    }

    for (int j = 0; j <= i ; j++){
        strv[j] = vector[j];
    }
    *size = i;
    return strv;
}

void split_free(char **split){
    if (!split) {
        return;
    }
    for (int i = 0; split[i]; i++){
        free(split[i]);
    }
    free(split);
}