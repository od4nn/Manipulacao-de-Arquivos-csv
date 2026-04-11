#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <string.h>

int gerar_resumo(void) {
    FILE *f = fopen("saida/resultado.csv", "r"); //abre o arquivo gigante de mais de 200 mil linhas

    if (f == NULL) {
        return ERR_ABRIR_RESULTADO;
    }

    Tribunal *inicio_lista = NULL; // a cabeça do nó

    char LINHA[TAM_LINHA];

    fgets(LINHA, TAM_LINHA, f); //consome o cabeçalho

    while (fgets(LINHA, TAM_LINHA, f) != NULL) { //enquanto nao chegar ao fim do arquivo

        /* Variaveis temporarias */

        char sigla_temp[TAM_SIGLA_TRIB];

        long long julgados_2026temp = 0;
        long long casos_novos_2026temp = 0;
        long long dessobrestados_2026temp = 0;
        long long suspensos_2026temp = 0;

        //para meta 2a
        long long julgm2_atemp = 0;
        long long distm2_atemp = 0;
        long long suspm2_atemp = 0;

        //meta 2ant
        long long julgm2_anttemp = 0;
        long long distm2_anttemp = 0;
        long long suspm2_anttemp = 0;
        long long desom2_anttemp = 0;

        //meta 4a
        long long julgm4_atemp = 0;
        long long distm4_atemp = 0;
        long long suspm4_atemp = 0;

        //meta 4b
        long long julgm4_btemp = 0;
        long long distm4_btemp = 0;
        long long suspm4_btemp = 0;

        char *token = strtok(LINHA, ",");
        int contador = 0;

        while (token != NULL) {
            switch (contador) {
                case 0: {
                    strcpy(sigla_temp, token);
                    break;
                }
                case 10: {
                    casos_novos_2026temp = atoll(token);
                    break;
                }
                case 11: {
                    julgados_2026temp = atoll(token);
                    break;
                }
                case 13: {
                    suspensos_2026temp = atoll(token);
                    break;
                }
                case 14: {
                    dessobrestados_2026temp = atoll(token);
                    break;
                }
                case 16: {
                    distm2_atemp = atoll(token);
                    break;
                }
                case 17: {
                    julgm2_atemp = atoll(token);
                    break;
                }
                case 18: {
                    suspm2_atemp = atoll(token);
                    break;
                }
                case 20: {
                    distm2_anttemp = atoll(token);
                    break;
                }
                case 21: {
                    julgm2_anttemp = atoll(token);
                    break;
                }
                case 22: {
                    suspm2_anttemp = atoll(token);
                    break;
                }
                case 23: {
                    desom2_anttemp = atoll(token);
                    break;
                }
                case 25: {
                    distm4_atemp = atoll(token);
                    break;
                }
                case 26: {
                    julgm4_atemp = atoll(token);
                    break;
                }
                case 27: {
                    suspm4_atemp = atoll(token);
                    break;
                }
                case 29: {
                    distm4_btemp = atoll(token);
                    break;
                }
                case 30: {
                    julgm4_btemp = atoll(token);
                    break;
                }
                case 31: {
                    suspm4_btemp = atoll(token);
                    break;
                }
            }
            token = strtok(NULL, ","); //faz com que na proxima volta o token comece de onte parou
            contador++;
        }

        Tribunal *aux = inicio_lista;
        int achou = 0;

        while (aux != NULL) {
            if (strcmp(aux->sigla_tribunal, sigla_temp) == 0) {
                aux->casos_novos_2026 += casos_novos_2026temp;
                aux->julgados_2026 += julgados_2026temp;
                aux->suspensos_2026 += suspensos_2026temp;
                aux->dessobrestados_2026 += dessobrestados_2026temp;

                aux->distm2_a += distm2_atemp;
                aux->julgm2_a += julgm2_atemp;
                aux->suspm2_a += suspm2_atemp;

                aux->distm2_ant += distm2_anttemp;
                aux->julgm2_ant += julgm2_anttemp;
                aux->suspm2_ant += suspm2_anttemp;
                aux->desom2_ant += desom2_anttemp;

                aux->distm4_a += distm4_atemp;
                aux->julgm4_a += julgm4_atemp;
                aux->suspm4_a += suspm4_atemp;

                aux->distm4_b += distm4_btemp;
                aux->julgm4_b += julgm4_btemp;
                aux->suspm4_b += suspm4_btemp;

                achou = 1; // se achou nao precisa ir para o if ali embaixo
                break;
            }
            aux = aux->prox;
        }

        if (achou == 0) { //Tribunal não existe ainda, vamos cria-lo
            Tribunal *novo_tribunal = malloc(sizeof(Tribunal)); // é um novo nó, mas tambem o novo tribunal e o novo inicio de lista

            if (novo_tribunal == NULL) {
                fclose(f);
                return ERR_ALOCAR_MEMORIA;
            }

            /* Copiando todos os dados do switch para o novo bloco de memoria que é
             * o novo tribunal. --------------------------
             * Da proxima vez que o loop rodar ele vai encontrar a sigla e nao
             * vai vir aqui, ele vai ficar em: while (aux != NULL) ate achar o estado */

            strcpy(novo_tribunal->sigla_tribunal, sigla_temp); //atribui nova sigla a esse bloco
            // Meta 1
            novo_tribunal->casos_novos_2026 = casos_novos_2026temp;
            novo_tribunal->julgados_2026 = julgados_2026temp;
            novo_tribunal->suspensos_2026 = suspensos_2026temp;
            novo_tribunal->dessobrestados_2026 = dessobrestados_2026temp;

            // Meta 2A
            novo_tribunal->distm2_a = distm2_atemp;
            novo_tribunal->julgm2_a = julgm2_atemp;
            novo_tribunal->suspm2_a = suspm2_atemp;

            // Meta 2Ant
            novo_tribunal->distm2_ant = distm2_anttemp;
            novo_tribunal->julgm2_ant = julgm2_anttemp;
            novo_tribunal->suspm2_ant = suspm2_anttemp;
            novo_tribunal->desom2_ant = desom2_anttemp;

            // Meta 4A
            novo_tribunal->distm4_a = distm4_atemp;
            novo_tribunal->julgm4_a = julgm4_atemp;
            novo_tribunal->suspm4_a = suspm4_atemp;

            // Meta 4B
            novo_tribunal->distm4_b = distm4_btemp;
            novo_tribunal->julgm4_b = julgm4_btemp;
            novo_tribunal->suspm4_b = suspm4_btemp;

            /* agora o novo tribunal aponta para o mais antigo. caso so existisse
             * Acre antes desse if e o while(fgets) ja chegou em alagoas, os nós
             * ficam estruturados assim agora:
             *
             * alagoas -> acre -> null
             * os que vao chegando vao ficando na frente de quem ja existia.
             *
             * e se nao existir nenhum tribunal ainda, fica assim:
             *
             * acre -> null
             * pq inicio_lista aponta para null la no começo */

            novo_tribunal->prox = inicio_lista;

            /* inicio_lista se torna agora o novo tribunal, pois, como falei
             * quem chega fica na frente de quem ja estava */

            inicio_lista = novo_tribunal;
        }
    }

    fclose(f); //se chegou aqui ja leu tudo

    FILE *saida = fopen("saida/resumo.csv", "w");

    if (saida == NULL) {

        //limpa antes de sair
        Tribunal *liberar = inicio_lista;
        while (liberar != NULL) {
            Tribunal *proximo = liberar->prox;
            free(liberar);
            liberar = proximo;
        }

        return ERR_ABRIR_ARQUIVO;
    }

    //colocando cabeçalho
    fprintf(saida, "Tribunal,Meta1,Meta2A,Meta2Ant,Meta4A,Meta4B\n");

    Tribunal *aux = inicio_lista;

    while (aux != NULL) {

        float meta1 = 0.0; //caso mesmo após toda a formula dê 0
        long long denominador_meta1 = aux->casos_novos_2026 +
            aux->dessobrestados_2026 - aux->suspensos_2026;
        if (denominador_meta1 != 0) { // é feito separado para evitar que divida por zero e de crashe o programa
            meta1 = ((float) aux->julgados_2026 / denominador_meta1) * 100;
        }

        float meta2a = 0.0;
        long long denominador_meta2a = aux->distm2_a - aux->suspm2_a;
        if (denominador_meta2a != 0) {
            meta2a = ((float) aux->julgm2_a / denominador_meta2a) * (1000.0 / 7.0);
        }

        float meta2ant = 0.0;
        long long denominador_meta2ant = aux->distm2_ant - aux->suspm2_ant
        - aux->desom2_ant;
        if (denominador_meta2ant != 0) {
            meta2ant = ((float) aux->julgm2_ant / denominador_meta2ant) * 100;
        }

        float meta4a = 0.0;
        long long denominador_meta4a = aux->distm4_a - aux->suspm4_a;
        if (denominador_meta4a != 0) {
            meta4a = ((float) aux->julgm4_a / denominador_meta4a) * 100;
        }

        float meta4b = 0.0;
        long long denominador_meta4b = aux->distm4_b - aux->suspm4_b;
        if (denominador_meta4b != 0) {
            meta4b = ((float) aux->julgm4_b / denominador_meta4b) * 100;
        }

        /* finalmente coloca no arquivo */
        fprintf(saida, "%s, %.2f, %.2f, %.2f, %.2f, %.2f\n", aux->sigla_tribunal,
            meta1, meta2a, meta2ant, meta4a, meta4b);

        aux = aux->prox; //avança para o proximo estado
        //nesse caso eles estao organizados do ultimo para o primeiro
    }
    fclose(saida); //fecha o arquivo de resposta


    /* percorre todos os nós dando free, afinal os dados deles ja foram usados */
    Tribunal *liberar = inicio_lista;
    while (liberar != NULL) {
        Tribunal *proximo = liberar->prox; // salva para o próximo antes de liberar
        free(liberar);                  // agora pode liberar
        liberar = proximo;              // avança pro próximo
    }

    return OK; // se chegou aqui, deu tudo certo e gerou o arquivo em saida/
}