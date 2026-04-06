#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>

int concatenar_dados(void) {
    char *arquivos[] = {
        "Base-de-Dados/teste_TRE-AC.csv",
        "Base-de-Dados/teste_TRE-AL.csv",
        "Base-de-Dados/teste_TRE-AM.csv",
        "Base-de-Dados/teste_TRE-AP.csv",
        "Base-de-Dados/teste_TRE-BA.csv",
        "Base-de-Dados/teste_TRE-CE.csv",
        "Base-de-Dados/teste_TRE-DF.csv",
        "Base-de-Dados/teste_TRE-ES.csv",
        "Base-de-Dados/teste_TRE-GO.csv",
        "Base-de-Dados/teste_TRE-MA.csv",
        "Base-de-Dados/teste_TRE-MG.csv",
        "Base-de-Dados/teste_TRE-MS.csv",
        "Base-de-Dados/teste_TRE-MT.csv",
        "Base-de-Dados/teste_TRE-PA.csv",
        "Base-de-Dados/teste_TRE-PB.csv",
        "Base-de-Dados/teste_TRE-PE.csv",
        "Base-de-Dados/teste_TRE-PI.csv",
        "Base-de-Dados/teste_TRE-PR.csv",
        "Base-de-Dados/teste_TRE-RJ.csv",
        "Base-de-Dados/teste_TRE-RN.csv",
        "Base-de-Dados/teste_TRE-RO.csv",
        "Base-de-Dados/teste_TRE-RR.csv",
        "Base-de-Dados/teste_TRE-RS.csv",
        "Base-de-Dados/teste_TRE-SC.csv",
        "Base-de-Dados/teste_TRE-SE.csv",
        "Base-de-Dados/teste_TRE-SP.csv",
        "Base-de-Dados/teste_TRE-TO.csv"
    }; //

    FILE *r = fopen("saida/resultado.csv", "w"); /* Optei por usar w
        porque a saida vai ser feita em um so arquivo dependendo de qual a opcao o usuario escolha
        e sempre vai sobrescrever a passada*/
    if (r == NULL) {
        return ERR_ABRIR_ARQUIVO;
    }

    for (int i = 0; i < QUANT_ESTADOS; i++) {

        FILE *f = fopen(arquivos[i], "r");
        if (f == NULL) {
            fclose (r); // Fecha o primeiro arquivo se o segundo falhar
            return ERR_ABRIR_ARQUIVO;
        }

        //se o estado for o primeiro, copiar tudo inclusive o cabeçalho
        if (i == 0) {    //faremos isso so uma vez porque todos os arquivos tem seus cabeçalhos
            char LINHA[TAM_LINHA];

            /* enquanto tiver linhas para ler continue executando, sei que o
             * != NULL é opcional mas optei por usar por clareza de codigo */
            while (fgets(LINHA, TAM_LINHA, f) != NULL) {

                fprintf(r, "%s\n", LINHA);
            }

            fclose(f);

            continue; //força a ir para o proximo loop ignorando o codigo abaixo
        }

        char LINHA[TAM_LINHA];

        fgets(LINHA, TAM_LINHA, f); //consome a primeira linha que é o cabeçalho

        while (fgets(LINHA, TAM_LINHA, f) != NULL) {
            fprintf(r, "%s", LINHA);
        }

        fclose(f);
    }

    fclose(r);

    return OK; //deu tudo certo
}

int gerar_resumo(void) {
    FILE *f = fopen("saida/resultado.csv", "r"); //abre o arquivo gigante de mais de 200 mil linhas

    if (f == NULL) {
        return ERR_ABRIR_RESULTADO;
    }

    char LINHA[TAM_LINHA];

    fgets(LINHA, TAM_LINHA, f); //consome o cabeçalho

    while (fgets(LINHA, TAM_LINHA, f) != NULL) { //enquanto nao chegar ao fim do arquivo

        /* Variaveis temporarias */

        char sigla_temp[TAM_SIGLA_TRIB];

        long long julgados_2026temp;
        long long casos_novos_2026temp;
        long long dessobrestados_2026temp;
        long long suspensos_2026temp;

        //para meta 2
        long long julgm2_atemp;
        long long distm2_atemp;
        long long suspm2_atemp;

        //meta 2ant
        long long julgm2_anttemp;
        long long distm2_anttemp;
        long long suspm2_anttemp;
        long long desom2_anttemp;

        //meta 4a
        long long julgm4_atemp;
        long long distm4_atemp;
        long long suspm4_atemp;

        //meta 4b
        long long julgm4_btemp;
        long long distm4_btemp;
        long long suspm4_btemp;

        char *token = strtok(LINHA, ",");
        int contador;

        while (token != NULL) {

        }
    }


}