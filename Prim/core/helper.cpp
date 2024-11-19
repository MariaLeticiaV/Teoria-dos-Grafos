#include <iostream>
#include "../include/helper.h"

void printHelper()
{
    printf("Bem-vindo à aplicação para resolver o problema da Árvore Geradora Mínima!\n");
    printf("Esta aplicação utiliza o algoritmo de Prim para encontrar a árvore geradora mínima em um grafo ponderado.\n\n");
  
    printf("Você pode escolher as seguintes opções ao executar o programa:\n");
    printf("-f <arquivo> : Lê os dados de entrada de um arquivo, contendo a definição do grafo com vértices e arestas.\n");
    printf("-o <arquivo> : Redireciona a saída da execução para o arquivo especificado, que conterá a solução do problema.\n");
    printf("-i <vertice> : Define o vértice inicial para o algoritmo de Prim. Este vértice será o ponto de partida para a construção da árvore geradora mínima.\n");
    printf("-s           : Exibe a solução do algoritmo, ou seja, as arestas da árvore geradora mínima e o custo total.\n");
    printf("-h           : Exibe este menu de ajuda, com explicações sobre o funcionamento do programa e as opções de terminal.\n\n");

    printf("Formato esperado para os dados de entrada:\n");
    printf("Cada linha deve representar uma aresta do grafo, no formato:\n");
    printf("<v1> <v2> <peso>\n");
    printf("Onde <v1> e <v2> são os vértices conectados por uma aresta e <peso> é o valor da aresta entre eles.\n");
    printf("Exemplo de entrada:\n");
    printf("1 2 10\n");
    printf("1 3 20\n");
    printf("2 3 5\n");
    printf("...\n\n");

    printf("A saída do algoritmo de Prim exibirá a árvore geradora mínima, ou seja, o conjunto de arestas que conectam todos os vértices com o menor custo total possível.\n");
    printf("Cada aresta selecionada será listada junto com seu peso, e ao final, o custo total de todas as arestas será mostrado.\n\n");
    printf("Nota: O algoritmo de Prim começa a partir de um vértice inicial e vai adicionando as arestas de menor peso à árvore geradora mínima, garantindo que não haja ciclos, até que todos os vértices estejam conectados.\n");
}
