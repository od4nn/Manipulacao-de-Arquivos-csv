# Processamento de Dados CSV com Lista Encadeada em C

## Descrição

Este projeto consiste no desenvolvimento de um programa em linguagem C para processamento de dados provenientes de arquivos no formato CSV (Comma-Separated Values).

O sistema tem como objetivo ler múltiplos arquivos contendo registros da Justiça Eleitoral, armazenar esses dados em memória utilizando uma estrutura de dados do tipo lista encadeada (TAD Lista) e, a partir disso, realizar operações específicas de transformação e geração de novos arquivos.

## Objetivo

Implementar um pipeline simples de processamento de dados que envolva:

* Leitura de arquivos CSV
* Armazenamento estruturado dos dados em memória
* Manipulação e análise dos registros
* Geração de arquivos de saída com base em regras definidas

## Funcionalidades

O programa deverá oferecer as seguintes operações:

### 1. Consolidação de Arquivos

Leitura de múltiplos arquivos CSV e geração de um único arquivo contendo todos os registros combinados.

### 2. Resumo por Tribunal

Agrupamento dos dados por `sigla_tribunal`, com cálculo de métricas agregadas (como somatórios de campos numéricos), resultando em um arquivo de resumo.

### 3. Filtro por Município

Filtragem dos registros com base no campo `municipio_oj`, gerando um arquivo contendo apenas os dados correspondentes ao município informado pelo usuário.

## Estrutura Geral

O funcionamento do programa segue o fluxo abaixo:

1. Leitura dos arquivos CSV
2. Conversão de cada linha em um registro estruturado
3. Armazenamento dos registros em uma lista encadeada
4. Execução das operações escolhidas pelo usuário
5. Geração de arquivos de saída

## Tecnologias Utilizadas

* Linguagem C (padrão ANSI C)
* Manipulação de arquivos (stdio.h)
* Estrutura de dados: Lista Encadeada

## Observações

* Cada linha dos arquivos CSV representa um registro independente.
* Os dados podem conter repetições que devem ser consideradas no processamento (especialmente em operações de agregação).
* O foco do projeto está na manipulação de dados em memória, sem uso de banco de dados.

---

## 📘 Guia de Contribuição do Projeto

Este documento define o fluxo de trabalho e a arquitetura do projeto. O objetivo destas diretrizes é garantir que múltiplos desenvolvedores possam contribuir simultaneamente sem gerar conflitos de código ou quebrar a compilação (build).

**Regra de Ouro:** Não é permitido o desenvolvimento simultâneo no mesmo arquivo para tarefas diferentes. Cada nova funcionalidade deve ser desenvolvida de forma modular.

---

### 1. Arquitetura e Modularização

O projeto adota uma arquitetura modularizada para evitar conflitos. As responsabilidades devem ser divididas da seguinte forma:

* **Arquivos de Cabeçalho (`.h`):**
    * Contêm as definições de `structs`, constantes e os protótipos (assinaturas) de todas as funções do sistema.
    * Sempre que uma nova função for criada em um módulo, sua assinatura deve ser declarada no arquivo `.h` correspondente.
* **Ponto de Entrada (`main.c`):**
    * Contém exclusivamente a função `main()`, o loop principal do programa e o menu de navegação.
    * Nenhuma lógica de negócio deve ser implementada diretamente aqui. Apenas chamadas para as funções modulares.
* **Módulos Específicos (`.c`):**
    * Cada nova entidade, funcionalidade ou grupo de tarefas (ex: operações de banco de dados, utilitários, regras de negócio) deve ser implementada em seu próprio arquivo `.c` exclusivo.

---

### 2. Configuração Inicial do Ambiente

Para iniciar o desenvolvimento pela primeira vez, siga os passos abaixo:

1.  **Clone o Repositório:**
    ```bash
    git clone <url-do-repositorio.git>
    ```

2.  **Abra o Projeto na IDE (Recomendado: CLion ou VS Code):**
    * Abra a pasta raiz clonada na sua IDE.
    * A IDE identificará automaticamente o arquivo `CMakeLists.txt` (se aplicável) e configurará o ambiente de compilação.
    * Certifique-se de que o *target* do executável correto está selecionado antes de compilar.

---

### 3. Fluxo de Trabalho (Workflow Git/CMake)

Para cada nova funcionalidade, melhoria ou correção de bug, siga rigorosamente a ordem abaixo:

#### Passo 1: Sincronize a Branch Principal (`main` ou `master`)
Antes de iniciar qualquer código, garanta que seu ambiente local está atualizado com a versão mais recente do repositório.

```bash
git checkout main
git pull
```

#### Passo 2: Crie uma Branch para a Tarefa
O desenvolvimento nunca deve ocorrer diretamente na branch principal. Crie uma branch descritiva para a sua tarefa.

```bash
git checkout -b feature-nome-da-tarefa 
# Exemplos: feature-login, bugfix-calculo-imposto
```

#### Passo 3: Implementação e Configuração do Build
Ao criar uma nova funcionalidade que exija um novo arquivo fonte (`.c` ou `.cpp`):

1.  **Crie o arquivo:** Ex: `src/novo_modulo.c`.
2.  **Atualize o Header:** Adicione o protótipo da função no `.h` adequado.
3.  **Implemente a lógica:** Escreva o código no seu novo arquivo.
4.  **Atualize o `CMakeLists.txt` (Obrigatório em projetos CMake):**
    O compilador precisa ser informado sobre o novo arquivo. Adicione o caminho do novo arquivo dentro da diretiva `add_executable`:
    ```cmake
    add_executable(nome_do_projeto 
        src/main.c 
        src/utils.c
        src/novo_modulo.c  # <-- Adicione o seu novo arquivo aqui
    )
    ```
5.  **Recarregue o Projeto:** Na IDE, recarregue o CMake/Makefile para aplicar as alterações na compilação.

#### Passo 4: Salve as Alterações (Commit)
Teste a aplicação localmente. Se a compilação e a execução forem bem-sucedidas:

```bash
git add .
git commit -m "Descricao clara e concisa do que foi feito"
```

#### Passo 5: Sincronização Pré-Envio (Resolução de Conflitos)
Antes de enviar o código, é fundamental verificar se a branch principal recebeu atualizações de outros desenvolvedores enquanto você trabalhava.

```bash
# Baixa as atualizações recentes da branch principal
git checkout main
git pull

# Retorna para a sua branch e aplica as atualizações nela
git checkout feature-nome-da-tarefa
git merge main
```
*Nota: Se ocorrerem conflitos no merge, resolva-os localmente na sua branch utilizando sua IDE antes de prosseguir.*

#### Passo 6: Envio das Alterações (Push)
Envie sua branch para o repositório remoto.

```bash
git push -u origin feature-nome-da-tarefa
```

#### Passo 7: Abertura do Pull Request (PR)
1. Acesse o repositório no GitHub/GitLab.
2. Abra um Pull Request da sua branch para a `main`.
3. Preencha o título e a descrição com os detalhes do que foi implementado, referenciando issues, se houver.
4. Aguarde a revisão de código (Code Review) pelos administradores ou colegas de equipe.

#### Passo 8: Revisão e Merge
* **Se o PR for aprovado:** O código será integrado (merged) pelo administrador.
* **Se alterações forem solicitadas (Request Changes):** * Mantenha o PR aberto.
    * Faça as correções localmente na mesma branch (`feature-nome-da-tarefa`).
    * Realize novos commits e um novo `git push`. O PR será atualizado automaticamente com as correções.

#### Passo 9: Limpeza (Pós-Merge)
Após o PR ser integrado com sucesso, exclua a branch local para manter seu ambiente organizado:

```bash
git checkout main
git pull
git branch -d feature-nome-da-tarefa
```

---

### 📋 Resumo de Comandos Diários

`git checkout main` ➔ `git pull` ➔ `git checkout -b [nova-branch]` ➔ *(código e build)* ➔ `git add .` ➔ `git commit` ➔ `git checkout main` ➔ `git pull` ➔ `git checkout [nova-branch]` ➔ `git merge main` ➔ `git push` ➔ *(Pull Request)* ➔ *(Merge)* ➔ `git branch -d [nova-branch]`

