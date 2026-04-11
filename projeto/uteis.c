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

void remover_acentos(char *str) {
    unsigned char *s = (unsigned char *) str;
    unsigned char *d = (unsigned char *) str;

    while (*s) {
        if (*s < 128) { // caractere ASCII normal, copia direto
            *d++ = *s++;
        } else { // dois bytes UTF-8, verifica qual é
            unsigned char c1 = *s++;
            unsigned char c2 = *s++;
            if (c1 == 0xC3) {
                if      (c2 >= 0x80 && c2 <= 0x85) *d++ = 'A'; // À Á Â Ã Ä Å
                else if (c2 >= 0xA0 && c2 <= 0xA5) *d++ = 'A'; // à á â ã ä å
                else if (c2 == 0x87)                *d++ = 'C'; // Ç
                else if (c2 == 0xA7)                *d++ = 'C'; // ç
                else if (c2 >= 0x88 && c2 <= 0x8B) *d++ = 'E'; // È É Ê Ë
                else if (c2 >= 0xA8 && c2 <= 0xAB) *d++ = 'E'; // è é ê ë
                else if (c2 >= 0x8C && c2 <= 0x8F) *d++ = 'I'; // Ì Í Î Ï
                else if (c2 >= 0xAC && c2 <= 0xAF) *d++ = 'I'; // ì í î ï
                else if (c2 >= 0x92 && c2 <= 0x96) *d++ = 'O'; // Ò Ó Ô Õ Ö
                else if (c2 >= 0xB2 && c2 <= 0xB6) *d++ = 'O'; // ò ó ô õ ö
                else if (c2 >= 0x99 && c2 <= 0x9C) *d++ = 'U'; // Ù Ú Û Ü
                else if (c2 >= 0xB9 && c2 <= 0xBC) *d++ = 'U'; // ù ú û ü
            }
        }
    }
    *d = '\0';
}