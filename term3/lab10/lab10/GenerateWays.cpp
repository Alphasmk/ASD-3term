#include "GenerateWays.h"
#include <iomanip>

int randNum(int start, int end)
{
    int r = end - start;
    int rnum = start + rand() % r;
    return rnum;
}

int** generateMatrix(int N)
{
    int** matrix = new int* [N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == i)
            {
                matrix[i][j] = 0;
            }
            else if (j > i)
            {
                matrix[i][j] = randNum(20, 90);
                matrix[j][i] = matrix[i][j];
            }
            else
            {
                matrix[i][j] = matrix[j][i];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return matrix;
}

map<pair<int, int>, double> generateWays(int** matrix, int N, double feromons)
{
    map<pair<int, int>, double> ways;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            ways[make_pair(i, j)] = feromons;
            ways[make_pair(j, i)] = feromons;
        }
    }

    return ways;
}
