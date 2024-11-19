#include "../headers/algorithm.h"

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

void helper();

int main(int argc, char **args)
{
    string input, output;
    int showEdges = 0;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(args[i], "-f") && i != argc - 1)
        {
            input = args[++i];
        }

        else if (!strcmp(args[i], "-f"))
        {
            cout << "Informe o caminho do arquivo de entrada\n";
            return 1;
        }

        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            output = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            cout << "Informe o caminho do arquivo de saida\n";
            return 1;
        }

        if (!strcmp(args[i], "-h"))
        {
            helper();
            return 0;
        }

        if (!strcmp(args[i], "-s"))
        {
            showEdges = 1;
        }
    }

    if (input.empty())
    {
        cout << "Por favor, informe um arquivo de entrada\n";
        return 1;
    }

    // Ler entradas
    ifstream inputFile(input);

    if (!inputFile.is_open())
    {
        cout << "Falha ao abrir arquivo de entrada\n";
        return 1;
    }

    string line;
    getline(inputFile, line);

    stringstream ss(line);
    int vertices, arestas;

    ss >> vertices >> arestas;

    // Definir tamanho e arestas do grafo
    Graph graph;

    graph.size = vertices;

    for (int i = 0; i < arestas; i++)
    {
        getline(inputFile, line);

        stringstream ss(line);
        int de, para, peso;

        ss >> de >> para >> peso;

        graph.edges.push_back({--de, --para, peso});
    }

    printKruskal(graph, showEdges, output);
    return 0;
}

void helper()
{
    cout << "Texto do helper\n";
}