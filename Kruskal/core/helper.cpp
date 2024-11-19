#include <iostream>
#include "../include/helper.h"

void printHelper()
{
    printf("Bem-vindo à aplicação para resolver o problema da Árvore Geradora Mínima!\n");
    printf("Esta aplicação utiliza o algoritmo de Kruskal para encontrar a árvore geradora mínima em um grafo ponderado.\n\n");
  
    printf("Ao executar o programa, você pode usar as seguintes opções:\n");
    printf("-f <arquivo> : Lê os dados de entrada de um arquivo. O arquivo deve conter a definição do grafo, com vértices e arestas.\n");
    printf("-o <arquivo> : Salva a saída da execução em um arquivo. A saída será a solução do problema da Árvore Geradora Mínima.\n");
    printf("-s           : Exibe a solução do algoritmo, ou seja, a árvore geradora mínima com as arestas selecionadas e o custo total.\n");
    printf("-h           : Exibe este menu de ajuda, com uma explicação das opções e do formato de entrada.\n\n");

    printf("Formato esperado para os dados de entrada:\n");
    printf("Cada linha deve representar uma aresta no grafo, no formato:\n");
    printf("<v1> <v2> <peso>\n");
    printf("Onde <v1> e <v2> são os vértices conectados por uma aresta, e <peso> é o peso dessa aresta.\n");
    printf("Exemplo de entrada:\n");
    printf("1 2 5\n");
    printf("2 3 3\n");
    printf("3 4 2\n");
    printf("...\n\n");

    printf("A saída do algoritmo exibirá a árvore geradora mínima, ou seja, o conjunto de arestas que conectam todos os vértices com o menor custo total possível.\n");
    printf("O programa exibirá cada aresta selecionada na árvore geradora mínima, juntamente com o peso dessa aresta.\n");
    printf("Além disso, o custo total de todas as arestas será mostrado no final.\n\n");
    printf("Nota: O algoritmo de Kruskal funciona selecionando as arestas de menor peso e conectando os vértices, garantindo que não haja ciclos, até que todos os vértices estejam conectados.\n");
}
