#ifndef MANIPULACAO_ARQUIVOS_LISTA_H
#define MANIPULACAO_ARQUIVOS_LISTA_H

/* -- DEFINES -- */

#define QUANT_ESTADOS 26
#define TAM_LINHA 1000 //acredite em mim, precisa ser grande assim se nao da problema no cabeçalho quando concatenar o arquivo
#define TAM_SIGLA_TRIB 10

typedef struct no{
    //identificador
    char sigla_tribunal[TAM_SIGLA_TRIB];

    //Para total e meta1
    long long julgados_2026;
    long long casos_novos_2026;
    long long dessobrestados_2026;
    long long suspensos_2026;

    //para meta 2
    long long julgm2_a;
    long long distm2_a;
    long long suspm2_a;

    //meta 2ant
    long long julgm2_ant;
    long long distm2_ant;
    long long suspm2_ant;
    long long desom2_ant;

    //meta 4a
    long long julgm4_a;
    long long distm4_a;
    long long suspm4_a;

    //meta 4b
    long long julgm4_b;
    long long distm4_b;
    long long suspm4_b;

    //o nó
    struct no *prox;
}Tribunal;

typedef enum {
    OK = 0, //sucesso geral

    /* Codigos de erro */

    ERR_ABRIR_ARQUIVO = -1, //erro fopen
    ERR_ABRIR_RESULTADO = -2, //erro ao abrir o resultado
    ERR_ALOCAR_MEMORIA = -3, //erro ao fazer malloc

}Codigos_Erro;

/* -- DECLARACAO DE FUNCOES -- */

int concatenar_dados(void); //junta tudo
int gerar_resumo(void); //faz um resumo de cada estado

#endif //MANIPULACAO_ARQUIVOS_LISTA_H