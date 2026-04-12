# Processamento de Dados CSV com Lista Encadeada em C

## Descrição

Este projeto consiste no desenvolvimento de um programa robusto em linguagem C para o processamento em massa de dados provenientes de arquivos no formato CSV (Comma-Separated Values). Originalmente desenvolvido como trabalho acadêmico para a disciplina de Estrutura de Dados (UCB), o sistema foi projetado para ler múltiplos arquivos contendo registros da Justiça Eleitoral, armazenar e manipular esses dados em memória utilizando o **Tipo Abstrato de Dados (TAD) Lista Encadeada**, e gerar relatórios consolidados e filtrados.

O foco principal do projeto é a manipulação eficiente de dados em memória e o uso seguro de ponteiros, garantindo performance e resiliência, incluindo tratamento de *memory leaks* e padronização de codificação de caracteres UTF-8, sem a utilização de bancos de dados externos.

## Funcionalidades

O programa oferece um menu interativo com as seguintes operações.

### Consolidação de Arquivos

Leitura automática de 27 arquivos CSV distintos, representando as bases estaduais, tratando a preservação do cabeçalho original apenas na primeira inserção e gerando um único arquivo consolidado com milhares de registros.

### Resumo de Metas por Tribunal

Processamento do arquivo consolidado, convertendo cada linha em um registro estruturado (`struct`) e alocando-o dinamicamente em uma **Lista Encadeada Simples**. O sistema calcula o cumprimento percentual de diversas metas processuais, como Metas 1, 2A, 2Ant, 4A e 4B, utilizando matemática de ponto flutuante e verificação contra divisões por zero, exportando um relatório analítico agrupado por sigla de tribunal.

### Filtro Específico por Município

Funcionalidade de busca profunda que filtra registros com base no município informado pelo usuário.

**Tratamento Avançado:** Inclui um algoritmo customizado de conversão e padronização de caracteres, capaz de remover acentos, tratando *bytes* hexadecimais do UTF-8, e homogeneizar *strings* (*case-insensitive*), garantindo que a busca funcione perfeitamente independentemente de o usuário ter digitado o município em maiúsculo ou minúsculo.

---

## 🚀 Como Executar o Projeto

Para testar o programa em seu ambiente local, siga as instruções de execução via terminal. O projeto não requer dependências externas além do compilador padrão C (GCC).

### Pré-requisitos

Compilador GCC instalado no sistema, em Windows, Linux ou Mac. A pasta `Base-de-Dados`, com os 27 arquivos `.csv` originais, e a pasta `saida`, para os relatórios, já estão inclusas e configuradas na estrutura deste repositório.

### Passo a Passo da Execução

**Clone o repositório:**

```bash
git clone <URL_DO_REPOSITORIO>
```

**Acesse a pasta do projeto:**

Navegue até o diretório exato onde o código-fonte e a base de dados estão localizados.

```bash
cd <NOME_DA_PASTA_CLONADA>/projeto
```

**Compile o código usando GCC:**

```bash
gcc main.c lista.c -o programa
```

**Execute o sistema:**

No Linux ou Mac:

```bash
./programa
```

No Windows:

```bash
programa.exe
```

**Dica:** Caso utilize uma IDE moderna como CLion ou VS Code, certifique-se de configurar o "Working Directory" da compilação para apontar exatamente para a pasta `projeto`. Isso garante que o executável consiga acessar as pastas de dados através dos caminhos relativos.

---

## Estrutura do Código

A arquitetura do projeto foi desenvolvida seguindo princípios de modularidade.

`lista.h`: Biblioteca contendo a definição da estrutura do nó (`Tribunal`), enumerações de erros padronizados e os protótipos de todas as funções do sistema.

`lista.c`: Módulo contendo a implementação lógica completa das operações de I/O de arquivos, inserção na lista encadeada, tratamento de strings e cálculos matemáticos.

`main.c`: Ponto de entrada do sistema, contendo a interface de usuário (*menu*) e as validações de input.

## Tecnologias Utilizadas

Linguagem C, padrão ANSI C.

Alocação dinâmica de memória, com `malloc` e `free`.

Manipulação avançada de ponteiros e strings, como `strtok` e `strcpy`.

Manipulação de arquivos via stream, com `stdio.h`.

Versionamento via Git/GitHub.

---

## 📘 Guia de Contribuição do Projeto

Este documento define o fluxo de trabalho e a arquitetura do projeto. O objetivo destas diretrizes é garantir que múltiplos desenvolvedores possam contribuir simultaneamente sem gerar conflitos de código ou quebrar a compilação, ou build.

**Regra de Ouro:** não é permitido o desenvolvimento simultâneo no mesmo arquivo para tarefas diferentes. Cada nova funcionalidade deve ser desenvolvida de forma modular.

### Arquitetura e Modularização

O projeto adota uma arquitetura modularizada para evitar conflitos. As responsabilidades devem ser divididas da seguinte forma.

**Arquivos de Cabeçalho (`.h`):** contêm as definições de `structs`, constantes e os protótipos, ou assinaturas, de todas as funções do sistema. Sempre que uma nova função for criada em um módulo, sua assinatura deve ser declarada no arquivo `.h` correspondente.

**Ponto de Entrada (`main.c`):** contém exclusivamente a função `main()`, o loop principal do programa e o menu de navegação. Nenhuma lógica de negócio deve ser implementada diretamente aqui, apenas chamadas para as funções modulares.

**Módulos Específicos (`.c`):** cada nova entidade, funcionalidade ou grupo de tarefas, como operações de banco de dados, utilitários ou regras de negócio, deve ser implementada em seu próprio arquivo `.c` exclusivo.

### Configuração Inicial do Ambiente

Para iniciar o desenvolvimento pela primeira vez, siga os passos abaixo.

**Clone o Repositório:**

```bash
git clone <url-do-repositorio.git>
```

**Abra o Projeto na IDE:** a recomendação é CLion ou VS Code. Abra a pasta raiz clonada na sua IDE. A IDE identificará automaticamente o arquivo `CMakeLists.txt`, se aplicável, e configurará o ambiente de compilação. Certifique-se de que o *target* do executável correto está selecionado antes de compilar.

### Fluxo de Trabalho (Workflow Git/CMake)

Para cada nova funcionalidade, melhoria ou correção de bug, siga rigorosamente a ordem abaixo.

#### Passo 1: Sincronize a Branch Principal (`main` ou `master`)

```bash
git checkout main
git pull
```

#### Passo 2: Crie uma Branch para a Tarefa

```bash
git checkout -b feature-nome-da-tarefa
```

Exemplos: `feature-login`, `bugfix-calculo-imposto`.

#### Passo 3: Implementação e Configuração do Build

```cmake
add_executable(nome_do_projeto
    src/main.c
    src/utils.c
    src/novo_modulo.c
)
```

#### Passo 4: Commit

```bash
git add .
git commit -m "Descricao clara e concisa do que foi feito"
```

#### Passo 5: Merge com main

```bash
git checkout main
git pull
git checkout feature-nome-da-tarefa
git merge main
```

#### Passo 6: Push

```bash
git push -u origin feature-nome-da-tarefa
```

#### Passo 9: Limpeza

```bash
git checkout main
git pull
git branch -d feature-nome-da-tarefa
```

### 📋 Resumo de Comandos Diários

```bash
git checkout main
git pull
git checkout -b [nova-branch]
git add .
git commit
git checkout main
git pull
git checkout [nova-branch]
git merge main
git push
git branch -d [nova-branch]
```
