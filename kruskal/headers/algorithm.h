#include <vector>
#include <string>

using namespace std;

struct Edge {
    int from, to, weight;
};

struct Graph {
    int size;
    vector<Edge> edges;
};

void printKruskal(Graph &graph, int showEdges, string output);