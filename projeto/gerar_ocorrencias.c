#include <stdio.h>
#include "lista.h"
#include <string.h>

int gerar_ocorrencias(char *MUNICIPIO) {
    FILE *f = fopen("saida/resultado.csv", "r");

    if (f == NULL) {
        return ERR_ABRIR_RESULTADO;
    }
    char caminho[100];
    snprintf(caminho, sizeof(caminho), "saida/%s.csv", MUNICIPIO);
    FILE *saida = fopen(caminho, "w");

    if (saida == NULL) {
        fclose (f);
        return ERR_ABRIR_ARQUIVO;
    }

    char LINHA[TAM_LINHA];
    int contador_aparicoes = 0;

    fgets (LINHA, TAM_LINHA, f);
    fprintf(saida, "%s", LINHA); //escreve o cabeçalho uma só vez

    while (fgets(LINHA, TAM_LINHA, f) != NULL) {

        /*faz uma copia da linha atual pq o strtok divide ela*/
        char salva_linha[TAM_LINHA];
        strcpy (salva_linha, LINHA);

        char *token = strtok(LINHA,",");
        int contador = 0;

        while (token != NULL) {
            if (contador == 5) { //5 é a posicao do municipio
                remover_aspas(token); //remove aspas do municipio antes de comparar com a que o usuario mandou (que ja esta sem as aspas)
                remover_acentos(token); //remove acento aqui pq o do usuario ja esta sem
                if (strcmp(token, MUNICIPIO) == 0) { //se municipio do arquivo for igual ao informado pelo usuario
                    fprintf(saida,"%s", salva_linha);
                    contador_aparicoes++;
                    break; //se a posicao 5 nao for o municipio desejado, avança uma linha
                }
            }
            contador++;
            token = strtok(NULL, ","); //vai para proxima virgula (proxima coluna) nessa linha
        }
    }

    fclose(f);
    fclose(saida);

    //se nao encontrar o municipio
    if (contador_aparicoes == 0) {
        remove(caminho);
        return ERR_MUNICIPIO_N_EXISTE;
    }

    return OK;
}