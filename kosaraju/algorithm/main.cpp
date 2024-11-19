#include <iostream>
#include <string.h>
#include "../headers/alghorithm.h"

using namespace std;

void helper();

int main(int argc, char **args)
{
    string output, input;

    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(args[i], "-h"))
        {
            helper();
            return 0;
        }

        if (!strcmp(args[i], "-o") && i != argc - 1)
        {
            output = args[++i];
        }
        else if (!strcmp(args[i], "-o"))
        {
            cout << "Por favor, informe o caminho do arquivo de saida\n";
            return 0;
        }

        if (!strcmp(args[i], "-f") && i != argc - 1)
        {
            input = args[++i];
        }
        else if (!strcmp(args[i], "-f"))
        {
            cout << "Por favor, informe o caminho do arquivo de entrada\n";
        }
    }

    kosaraju(input, output);
    return 0;
}

void helper() {
    cout << "Texto do helper\n";
}