#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <list>
#include <string>

using namespace std;

struct Edge
{
    int from, to, weight;
};

class Graph
{
public:
    vector<list<pair<int, int>>> adj;
    vector<pair<int, int>> mstEdges;
    int size;

    Graph(int size);

    void setEdge(int u, int v, int w);
    void printPrim(int initial, int solution, string output);
};

#endif
