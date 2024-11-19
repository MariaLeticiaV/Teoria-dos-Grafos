#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <fstream>
#include "../headers/algorithm.h"

using namespace std;

typedef pair<int, int> pii;

void printDijkstra(vector<vector<pii>> &graph, int size, int initial, string output)
{
    ofstream outFile(output);

    vector<int> dist(size, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> queue;

    queue.push({0, initial});
    dist[initial] = 0;

    while (!queue.empty())
    {
        int u = queue.top().second;
        int d = queue.top().first;

        queue.pop();

        for (auto &edge : graph[u])
        {
            if (d > dist[u])
            {
                continue;
            }

            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                queue.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        int value = dist[i] == INT_MAX ? -1 : dist[i];

        cout << i + 1 << ":" << value << " ";

        if (outFile.is_open())
        {
            outFile << i + 1 << ":" << value << " ";
        }
    }

    cout << endl;

    if (outFile.is_open())
    {
        outFile << endl;
        outFile.close();
    }
}