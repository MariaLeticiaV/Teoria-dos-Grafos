#include <iostream>
#include "../include/helper.h"

void printHelper()
{
    printf("Bem-vindo à aplicação de cálculo da distância mínima entre vértices!\n");
    printf("Esta ferramenta utiliza o algoritmo de Dijkstra para encontrar o caminho mais curto entre dois vértices em um grafo ponderado.\n\n");
  
    printf("As opções que você pode escolher ao executar o programa são:\n");
    printf("-f <arquivo> : Lê os dados de entrada a partir do arquivo especificado (formato de grafo).\n");
    printf("-o <arquivo> : Salva a saída do programa em um arquivo de sua escolha.\n");
    printf("-i <vertice> : Define o vértice inicial para calcular a distância mínima.\n");
    printf("-h           : Exibe este menu de ajuda, mostrando todas as opções disponíveis.\n\n");

    printf("Formato esperado para o grafo de entrada:\n");
    printf("Cada linha define uma aresta no formato:\n");
    printf("-<v1> -<v2> -<peso>\n");
    printf("Onde <v1> e <v2> são os vértices conectados e <peso> é o valor da aresta entre eles.\n");
    printf("Exemplo de entrada:\n");
    printf("1 2 5\n");
    printf("2 3 3\n");
    printf("...\n\n");

    printf("Nota: Ao utilizar a opção -i, o vértice inicial deve ser um número válido presente no grafo.\n");
    printf("A saída mostra a distância mínima entre o vértice escolhido e os outros vértices conectados.\n\n");
}
