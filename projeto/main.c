#include <stdio.h>
#include <string.h>
#include "lista.h"
#include <ctype.h>

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
        limpar_buffer(); /* limpa o buffer para evitar que tenha
        quebra de linha em fgets futuros */

        switch (opcao) {
            case 1: {
                int resultado = concatenar_dados();

                if (resultado == OK) {
                    printf("\nSucesso! O arquivo de resultado foi gerado"
                           " na pasta 'saida'. ");
                    break;
                }
                if (resultado == ERR_ABRIR_ARQUIVO) {
                    printf("\nErro: ao abrir o arquivo!");
                    break;
                }
                break;
            }

            case 2: {
                int resultado = gerar_resumo();

                switch (resultado) {
                    case OK: {
                        printf("\nSucesso! O arquivo de resumo foi gerado na "
                           "pasta 'saida'.");
                        break;
                    }
                    case ERR_ABRIR_RESULTADO: {
                        printf("\nErro: arquivo 'resultado' nao encontrado! "
                           "Voce deve gerar esse arquivo na opcao 1 "
                           "do menu antes de usar esta funcao.");
                        break;
                    }
                    case ERR_ABRIR_ARQUIVO: {
                        printf("\nErro: ao abrir o arquivo na pasta 'saida'!");
                        break;
                    }
                    case ERR_ALOCAR_MEMORIA: {
                        printf("\nErro: ao alocar memoria!");
                        break;
                    }
                    default: {
                        printf("\nErro desconhecido...");
                    }
                }
                break;
            }

            case 3: {
                char NOME_MUNICIPIO[TAM_NOME_MUNICIPIO];

                printf("Informe o nome do municipio que deseja"
                       " procurar as ocorrencias: ");
                fgets(NOME_MUNICIPIO, TAM_NOME_MUNICIPIO, stdin);
                //remove o \n da string
                NOME_MUNICIPIO[strcspn(NOME_MUNICIPIO, "\n")] = '\0';

                remover_aspas(NOME_MUNICIPIO); //vai que o usuario acha que tem que colocar aspas

                int tamanho_municipio = strlen(NOME_MUNICIPIO);

                for (int i = 0; i < tamanho_municipio; i++) { //deixa toda string maiscula
                    NOME_MUNICIPIO[i] = toupper(NOME_MUNICIPIO[i]);
                }

                int resultado = gerar_ocorrencias(NOME_MUNICIPIO);

                switch (resultado) {
                    case OK: {
                        printf("\nSucesso! O arquivo de ocorrencias foi gerado na "
                           "pasta 'saida'.");
                        break;
                    }
                    case ERR_ABRIR_RESULTADO: {
                        printf("\nErro: arquivo 'resultado' nao encontrado! "
                           "Voce deve gerar esse arquivo na opcao 1 "
                           "do menu antes de usar esta funcao.");
                        break;
                    }
                    case ERR_ABRIR_ARQUIVO: {
                        printf("\nErro: ao abrir o arquivo na pasta 'saida'!");
                        break;
                    }
                    case ERR_MUNICIPIO_N_EXISTE: {
                        printf("\nErro: o municipio informado nao foi "
                               "encontrado. Verifique se ele existe ou se digitou "
                               "seu nome corretamente.");
                        break;
                    }
                    default: {
                        printf("\nErro desconhecido...");
                    }
                    break;
                }
                break;
            }

            case 0: {
                printf("\nEncerrando o programa...\n");
                break;
            }

            default: {
                printf("\nEscolha uma opcao valida!");
            }
        }

    }while (opcao != 0);
    return 0;
}
