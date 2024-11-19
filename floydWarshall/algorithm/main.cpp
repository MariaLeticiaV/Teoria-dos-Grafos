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
    cout << "Eee\n";
}