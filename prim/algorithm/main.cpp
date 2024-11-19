#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include "../headers/algorithm.h"

using namespace std;

void helper();

int main(int argc, char **args)
{
    string input, output;
    int showEdges = 0, initial = 1;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(args[i], "-s"))
        {
            showEdges = 1;
        }

        if (!strcmp(args[i], "-h"))
        {
            helper();
            return 0;
        }

        if (!strcmp(args[i], "-f") && i != argc - 1)
        {
            input = args[++i];
        }
        else if (!strcmp(args[i], "-f"))
        {
            cout << "Por favor, informe o arquivo de entrada\n";
            return 1;
        }

        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            output = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            cout << "Por favor, informe o arquivo de saida\n";
            return 1;
        }

        if (!strcmp(args[i], "-i") && i != argc - 1)
        {
            initial = stoi(args[++i]);
        }
        else if (!strcmp(args[i], "-i"))
        {
            cout << "Por favor, informe o vertice inicial\n";
            return 1;
        }
    }

    // Ler as entradas do usuario
    // - Definir tamanho do grafo e suas arestas
    ifstream inputFile(input);

    if (!inputFile.is_open())
    {
        cout << "Falha ao abrir arquivo informado\n";
        return 1;
    }

    string line;
    getline(inputFile, line);

    stringstream ss(line);

    int vertices, arestas;
    ss >> vertices >> arestas;

    Graph g(vertices);

    for (int i = 0; i < arestas; i++)
    {
        getline(inputFile, line);
        stringstream ss(line);

        int de, para, peso;
        ss >> de >> para >> peso;

        g.setEdge(--de, --para, peso);
    }

    inputFile.close();

    g.printPrim(--initial, showEdges, output);
    return 0;
}

void helper()
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
