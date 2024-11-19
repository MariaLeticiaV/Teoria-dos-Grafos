#include "../headers/algorithm.h"

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

void helper();

int main(int argc, char **args)
{
    string input, output;
    int inicial = 1;

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
            cout << "Por favor, informe um arquivo de entrada\n";
            return 1;
        }

        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            output = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            cout << "Por favor, informe um arquivo de saida\n";
            return 1;
        }

        if (!strcmp(args[i], "-i") && i != argc - 1)
        {
            inicial = stoi(args[++i]);
        }
        else if (!strcmp(args[i], "-i"))
        {
            cout << "Por favor, informe um vertice inicial\n";
            return 1;
        }
    }

    ifstream inputFile(input);
    string line;

    if (!inputFile.is_open())
    {
        cout << "Falha ao abrir arquivo de entrada, verifique o caminho\n";
        return 1;
    }

    getline(inputFile, line);

    stringstream ss(line);
    int vertices, arestas;

    ss >> vertices >> arestas;

    vector<vector<pii>> graph(vertices);

    for (int i = 0; i < arestas; i++)
    {
        getline(inputFile, line);

        int src, dest, weight;
        stringstream ss(line);

        ss >> src >> dest >> weight;

        graph[src - 1].push_back({dest - 1, weight});
        graph[dest - 1].push_back({src - 1, weight});
    }

    printDijkstra(graph, vertices, inicial - 1, output);
    inputFile.close();

    return 0;
}

void helper() {
    cout << "Esse eh o helper hohoho" << endl;
}
