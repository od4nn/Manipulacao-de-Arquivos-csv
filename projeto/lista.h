
#ifndef MANIPULACAO_ARQUIVOS_LISTA_H
#define MANIPULACAO_ARQUIVOS_LISTA_H

/* -- DEFINES -- */

#define QUANT_ESTADOS 26
#define TAM_LINHA 200 //mais que suficiente para cada linha dos arquivos das bases de dados


typedef enum {
    OK = 0, //sucesso geral

    /* Codigos de erro */

    ERR_ABRIR_ARQUIVO = -1, //erro fopen

}Codigos_Erro;

/* -- DECLARACAO DE FUNCOES -- */

int concatenar_dados(void);

#endif //MANIPULACAO_ARQUIVOS_LISTA_H