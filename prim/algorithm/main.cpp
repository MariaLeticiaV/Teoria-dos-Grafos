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
    cout << "Texto do helper\n";
}
