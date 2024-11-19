#include "../headers/algorithm.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool compareWeight(Edge e1, Edge e2);
void setUnion(vector<int> &parent, int x, int y);
int find(vector<int> &parent, int i);

void printKruskal(Graph &graph, int showEdges, string outputPath)
{
    vector<int> parent(graph.size, -1);
    vector<Edge> result;

    sort(graph.edges.begin(), graph.edges.end(), compareWeight);

    for (auto edge : graph.edges)
    {
        int x = find(parent, edge.from);
        int y = find(parent, edge.to);

        if (x != y)
        {
            result.push_back(edge);
            setUnion(parent, x, y);
        }
    }

    // Exibir resultado
    ofstream outfile(outputPath);
    int totalWeight = 0;

    for (auto edge : result)
    {
        if (edge.weight > 0)
        {
            totalWeight += edge.weight;
        }

        if (showEdges && outfile.is_open())
        {
            cout << "(" << edge.from + 1 << ", " << edge.to + 1 << ") ";

            if (outfile.is_open())
            {
                outfile << "(" << edge.from + 1 << ", " << edge.to + 1 << ") ";
            }
        }
    }

    if (!showEdges)
    {
        cout << totalWeight << " \n";

        if (outfile.is_open())
        {
            outfile << totalWeight << " \n";
            outfile.close();
        }
    }

    if (showEdges)
    {
        cout << endl;

        if (outfile.is_open())
        {
            outfile << endl;
            outfile.close();
        }
    }
}

int find(vector<int> &parent, int i)
{
    if (parent[i] == -1)
    {
        return i;
    }

    return find(parent, parent[i]);
}

void setUnion(vector<int> &parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

    parent[xset] = yset;
}

bool compareWeight(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
