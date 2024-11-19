#include "../headers/algorithm.h"

#include <iostream>
#include <vector>
#include <climits>
#include <limits.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

void printSolution(const vector<vector<int>> &distances, int size, ofstream &outputFile)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "Vertice: " << i + 1 << endl;

        if (outputFile.is_open())
        {
            outputFile << "Vertice: " << i + 1 << endl;
        }

        for (int j = 0; j < size; ++j)
        {
            int value;

            if (distances[i][j] == INT_MAX)
            {
                value = -1;
            }
            else
            {
                value = distances[i][j];
            }

            cout << "(" << j + 1 << " -> " << value << ") ";

            if (outputFile.is_open())
            {
                outputFile << "(" << j + 1 << " -> " << value << ") ";
            }
        }

        cout << "\n\n";

        if (outputFile.is_open())
        {
            outputFile << "\n\n";
        }
    }

    if (outputFile.is_open())
    {
        outputFile.close();
    }
}

void floydWarshall(vector<vector<int>> &distances, int size, string output)
{
    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX &&
                    distances[i][j] > (distances[i][k] + distances[k][j]))
                {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    ofstream outputFile(output);

    for (int i = 0; i < size; i++)
    {
        if (distances[i][i] < 0)
        {
            cout << "Vertice " << i + 1 << " contem ciclo negativo\n";

            if (outputFile.is_open())
            {
                outputFile << "Vertice " << i + 1 << " contem ciclo negativo\n";
            }

            return;
        }
    }

    printSolution(distances, size, outputFile);
}
