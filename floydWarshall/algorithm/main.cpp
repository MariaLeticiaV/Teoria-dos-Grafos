#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <sstream>
#include <climits>

#include "../headers/algorithm.h"

using namespace std;

void helper();

int main(int argc, char **args)
{
    string input, output;

    for (int i = 0; i < argc; i++)
    {
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
            cout << "Informe um caminho para o arquivo de entrada\n";
            return 1;
        }

        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            output = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            cout << "Informe um valor para o vertice inicial\n";
            return 1;
        }
    }

    ifstream inputFile(input);
    int size, edges;

    if (input.empty())
    {
        cout << "Informe um arquivo de entrada\n";
        return 1;
    }

    if (!inputFile.is_open())
    {
        cout << "Falha ao abrir arquivo de entrada\n";
        return 1;
    }

    string line;
    getline(inputFile, line);

    stringstream ss(line);
    ss >> size >> edges;

    vector<vector<int>> graph(size, vector<int>(size, INT_MAX));

    for (int i = 0; i < size; i++)
    {
        graph[i][i] = 0;
    }

    for (int i = 0; i < edges; i++)
    {
        getline(inputFile, line);
        stringstream ss(line);

        int from, to, weight;
        ss >> from >> to >> weight;

        graph[--from][--to] = weight;
    }

    floydWarshall(graph, size, output);
    return 0;
}

void helper()
{
    printf("Bem-vindo à aplicação que resolve o problema do caminho mínimo entre todos os pares de vértices em um grafo ponderado!\n");
    printf("Esta aplicação utiliza o algoritmo de Floyd-Warshall, que calcula as distâncias mínimas entre cada par de vértices de um grafo.\n\n");

    printf("Você pode usar as seguintes opções ao executar o programa:\n");
    printf("-f <arquivo> : Lê os dados de entrada de um arquivo. O arquivo deve conter a definição do grafo, com vértices e arestas.\n");
    printf("-o <arquivo> : Salva a saída da execução em um arquivo. A saída será a matriz de distâncias mínimas entre todos os pares de vértices.\n");
    printf("-h           : Exibe este menu de ajuda, explicando as opções disponíveis e o funcionamento do programa.\n\n");

    printf("Formato esperado para os dados de entrada:\n");
    printf("O arquivo de entrada deve listar as arestas do grafo no seguinte formato:\n");
    printf("<v1> <v2> <peso>\n");
    printf("Onde <v1> e <v2> são os vértices conectados por uma aresta, e <peso> é o valor (peso) da aresta entre eles.\n");
    printf("Exemplo de entrada:\n");
    printf("1 2 10\n");
    printf("1 3 5\n");
    printf("2 3 3\n");
    printf("...\n\n");

    printf("A saída do algoritmo será uma matriz de distâncias mínimas entre todos os pares de vértices.\n");
    printf("Cada elemento da matriz representa a distância mínima entre os vértices correspondentes.\n");
    printf("Se não houver caminho entre dois vértices, a distância será representada por um valor infinito (geralmente um número muito grande).\n\n");

    printf("Nota: O algoritmo de Floyd-Warshall é um algoritmo de programação dinâmica que calcula, para todos os pares de vértices, o caminho de custo mínimo. ");
    printf("O algoritmo tem complexidade O(V^3), onde V é o número de vértices no grafo.\n");
}
