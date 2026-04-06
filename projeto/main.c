#include <stdio.h>

#include "lista.h"

int main() {
    int opcao;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Concatenar Arquivos\n");
        printf("2. Gerar resumo\n");
        printf("3. Gerar todas as ocorrencias\n");
        printf("0. Encerrar programa\n");
        printf("\nEscolha uma opcao: ");

        scanf("%d", &opcao);
        while (getchar() != '\n'); /* limpa o buffer para evitar que tenha
        quebra de linha em fgets futuros */

        switch (opcao) {
            case 1: {

                int resultado = concatenar_dados();

                if (resultado == OK) {
                    printf("\nSucesso! O arquivo foi gerado na pasta 'saida'. ");
                    break;
                }
                if (resultado == ERR_ABRIR_ARQUIVO) {
                    printf("\nErro ao abrir o arquivo!");
                    break;
                }
            }
            case 0: {
                printf("\nEncerrando o programa...\n");
                break;
            }
            default: {
                printf("Escolha uma opcao valida!");
            }
        }



    }while (opcao != 0);
    return 0;
}
