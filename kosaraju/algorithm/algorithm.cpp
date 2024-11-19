
#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <sstream>
#include <string>
#include "../headers/alghorithm.h"

using namespace std;

class Graph
{
    vector<vector<int>> adjMatrix;

public:
    Graph(int vectorCount)
    {
        adjMatrix = vector<vector<int>>(vectorCount, vector<int>(vectorCount, 0));
    }

    void addEdge(int src, int dest)
    {
        adjMatrix[src][dest] = 1;
    }

    Graph invert()
    {
        int size = adjMatrix.size();

        Graph graph(size);

        for (int from = 0; from < size; from++)
        {
            for (int to = 0; to < size; to++)
            {
                if (adjMatrix[from][to])
                {
                    graph.addEdge(to, from);
                }
            }
        }

        return graph;
    }

    void print(string output)
    {
        ofstream outfile(output);

        Graph reversed = this -> invert();
        stack<int> stack;
        vector<int> visited(adjMatrix.size(), false);

        for (unsigned int i = 0; i < adjMatrix.size(); i++)
        {
            if (!visited[i])
            {
                DFS(i, visited, stack, reversed);
            }
        }

        fill(visited.begin(), visited.end(), false);

        while (stack.size())
        {
            int v = stack.top();

            stack.pop();

            if (!visited[v])
            {
                DFSUtil(v, visited, adjMatrix, outfile);

                cout << endl;

                if (outfile.is_open())
                {
                    outfile << endl;
                }
            }
        }

        if (outfile.is_open())
        {
            outfile.close();
        }
    }

private:
    void DFS(int v, vector<int> &visited, stack<int> &st, Graph &graph)
    {
        visited[v] = 1;

        for (unsigned int i = 0; i < graph.adjMatrix.size(); i++)
        {
            if (graph.adjMatrix[v][i] && !visited[i])
            {
                DFS(i, visited, st, graph);
            }
        }

        st.push(v);
    }

    void DFSUtil(int v, vector<int> &visited, vector<vector<int>> &adj, ofstream &file)
    {
        visited[v] = 1;

        cout << v + 1 << " ";

        if (file.is_open())
        {
            file << v + 1 << " ";
        }

        for (unsigned int i = 0; i < adj.size(); i++)
        {
            if (adj[v][i] && !visited[i])
            {
                DFSUtil(i, visited, adj, file);
            }
        }
    }
};

int kosaraju(string inputPath, string output)
{
    ifstream inputFile(inputPath);

    if (!inputFile.is_open())
    {
        cout << "Falha ao abrir o arquivo de entrada\n";
        return 1;
    }

    int vertices, arestas;
    string line;

    getline(inputFile, line);

    stringstream ss(line);
    ss >> vertices >> arestas;

    Graph graph(vertices);

    for (int i = 0; i < arestas; i++)
    {
        getline(inputFile, line);

        stringstream ss(line);

        int src, dest;
        ss >> src >> dest;

        graph.addEdge(src - 1, dest - 1);
    }

    inputFile.close();
    graph.print(output);

    return 0;
}