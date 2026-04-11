#include <stdio.h>
#include "lista.h"
#include <string.h>

void remover_aspas(char *str) {
    int tamanho = strlen(str);
    if (tamanho > 0 && str[0] == '"') {
        memmove(str, str + 1, tamanho); // remove a primeira aspas
        tamanho--;
    }
    if (tamanho > 0 && str[tamanho - 1] == '"') {
        str[tamanho - 1] = '\0'; // remove a última aspas
    }
}

void limpar_buffer(void) {
    /* limpa o buffer para evitar que tenha
        quebra de linha em fgets futuros */
    while (getchar() != '\n');
}