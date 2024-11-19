#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
#include <string>
#include <fstream>
#include "../headers/algorithm.h"

using namespace std;

Graph::Graph(int size)
{
    this->size = size;
    adj.resize(size);
}

void Graph::setEdge(int u, int v, int w)
{
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
}

void Graph::printPrim(int initial, int showEdges, string output)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<bool> inMST(size, false);
    vector<int> key(size, INT_MAX);
    vector<int> parent(size, -1);

    ofstream outfile(output);

    key[initial] = 0;
    queue.push(make_pair(0, initial));

    while (!queue.empty())
    {
        int u = queue.top().second;
        queue.pop();

        if (inMST[u])
        {
            continue;
        }

        inMST[u] = true;

        for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            int v = it->first;
            int weight = it->second;

            if (inMST[v] || key[v] <= weight)
            {
                continue;
            }

            key[v] = weight;
            parent[v] = u;
            queue.push(make_pair(key[v], v));
        }
    }

    int totalWeight = 0;

    for (int i = 1; i < size; ++i)
    {
        totalWeight += key[i];
        mstEdges.push_back(make_pair(parent[i], i));
    }

    if (!showEdges) {
        cout << totalWeight << endl;
    }

    if (!showEdges && outfile.is_open())
    {
        outfile << totalWeight << endl;
        outfile.close();
    }

    if (!showEdges)
    {
        return;
    }

    for (auto edge : mstEdges)
    {
        cout << "(" << edge.first + 1 << ", " << edge.second + 1 << ") ";

        if (outfile.is_open())
        {
            outfile << "(" << edge.first + 1 << ", " << edge.second + 1 << ") ";
        }
    }

    cout << endl;

    if (outfile.is_open())
    {
        outfile << endl;
        outfile.close();
    }
}