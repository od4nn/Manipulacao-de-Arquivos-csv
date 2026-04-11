cmake_minimum_required(VERSION 3.28)
project(Manipulacao_Arquivos C)

set(CMAKE_C_STANDARD 11)

add_executable(Manipulacao_Arquivos
        projeto/main.c
        projeto/lista.h
        projeto/lista.c
        projeto/gerar_resumo.c
        projeto/gerar_ocorrencias.c
        projeto/uteis.c
)