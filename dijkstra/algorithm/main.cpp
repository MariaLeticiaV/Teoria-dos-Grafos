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
