#include "generatePapulation.h"
#include <set>
const int INF = 1000000;

vector<pair<vector<int>, int>> generatePopulation(vector<vector<int>> matrix, int choice)
{
    vector<pair<vector<int>, int>> population;
    int count = 0;
    srand(time(0));
    do
    {
        vector<int> individual;
        int start_index = 0;
        individual.push_back(start_index);
        int randomIndex;
        int way = 0;
        set<int> visited;
        visited.insert(start_index);
        for (int i = 1; i < matrix.size(); i++)
        {
            do
            {
                randomIndex = rand() % matrix.size();
            } while (matrix[start_index][randomIndex] == INF || visited.count(randomIndex) == 1);
            individual.push_back(randomIndex);
            start_index = randomIndex;
            visited.insert(randomIndex);
        }
        for (int i = 1; i < individual.size(); i++)
        {
            way += matrix[individual[i]][individual[i - 1]];
        }
        population.push_back({ individual, way });
        count++;
    } while (count < choice);
    return population;
}
