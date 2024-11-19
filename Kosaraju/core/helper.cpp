#include <iostream>
#include <string.h>
#include "helper.h"

using namespace std;

void printHelper()
{
    printf("Bem-vindo ao aplicativo de identificação de componentes fortemente conexas!\n");
    printf("Este programa utiliza o algoritmo de Kosaraju para encontrar e listar as componentes fortemente conexas de um grafo direcionado.\n\n");

    printf("Você pode usar as seguintes opções ao executar o programa:\n");
    printf("-f <arquivo> : Lê os dados de entrada de um arquivo, que deve conter a definição do grafo.\n");
    printf("-o <arquivo> : Salva o resultado da execução em um arquivo especificado.\n");
    printf("-h           : Exibe este menu de ajuda, mostrando todas as opções disponíveis.\n\n");

    printf("Formato de entrada esperado:\n");
    printf("Cada linha do arquivo de entrada deve representar uma aresta do grafo, no formato:\n");
    printf("<v1> <v2>\n");
    printf("Onde <v1> é o vértice de origem e <v2> é o vértice de destino, formando uma aresta direcionada.\n");
    printf("Exemplo de entrada:\n");
    printf("1 2\n");
    printf("2 3\n");
    printf("3 4\n");
    printf("...\n\n");

    printf("Após a execução, as componentes fortemente conexas serão listadas individualmente, uma por linha.\n");
    printf("Cada linha representa uma componente conexa distinta do grafo.\n\n");

    printf("Nota: Este algoritmo de Kosaraju divide o grafo em subcomponentes onde cada vértice está fortemente conectado a outros dentro da mesma componente.\n");
}
