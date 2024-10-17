#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <utility>

using namespace std;

const int V = 8;

void PrimsAlgorithm(int);
void KruskalAlgorithm();

int adjacencyMatrix[V][V] = {
    {0, 2, 0, 8, 2, 0, 0, 0},
    {2, 0, 3, 10, 5, 0, 0, 0},
    {0, 3, 0, 0, 12, 0, 0, 7},
    {8, 10, 0, 0, 14, 3, 1, 0},
    {2, 5, 12, 14, 0, 11, 4, 8},
    {0, 0, 0, 3, 11, 0, 6, 0},
    {0, 0, 0, 1, 4, 6, 0, 9},
    {0, 0, 7, 0, 8, 0, 9, 0}
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "\tМатрица смежности: " << endl;
    cout << "   ";
    for (int i = 0; i < V; i++)
    {
        cout << setw(2) << "V" << i + 1;
    }

    cout << endl;
    for (int i = 0; i < V; i++)
    {
        cout << setw(2) << "V" << i + 1;
        for (int j = 0; j < V; j++)
        {
            cout << setw(3) << adjacencyMatrix[i][j];
        }
        cout << endl;
    }

    int startVertex;
    do
    {
        cout << "\nВведите стартовую вершину: ";
        cin >> startVertex;
        if (startVertex < 1 || startVertex > 8)
        {
            cout << "Неверная стартовая вершина\n\n";
        }
    } while (startVertex < 1 || startVertex > 8);

    PrimsAlgorithm(startVertex - 1);
    KruskalAlgorithm();

    int edges = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++) 
        {
            if (adjacencyMatrix[i][j] > 0)
            {
                edges++;
            }
        }
    }

    int cyclomaticNumber = edges - V + 1;

    cout << "\nЦикломатическое число графа: " << cyclomaticNumber << endl;

    return 0;
}

void PrimsAlgorithm(int start)
{
    struct PairValue
    {
        pair<int, int> edge;
        int value;
    };

    vector<PairValue> vec;
    bool visited[V] = { false };
    int edgeCount = 0;
    while (edgeCount != V - 1)
    {
        visited[start] = true;
        pair<int, int> minVert;
        int minValue = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == true)
            {
                for (int j = 0; j < V; j++)
                {
                    if (adjacencyMatrix[i][j] < minValue && adjacencyMatrix[i][j] != 0 && visited[j] != true)
                    {
                        minVert.first = i;
                        minVert.second = j;
                        minValue = adjacencyMatrix[i][j];
                    }
                }
            }
        }
        vec.push_back({ {minVert.first, minVert.second}, minValue });
        start = minVert.second;
        edgeCount++;
    }

    int sum = 0;

    cout << "\n\tАлгоритм Прима\n\tСписок ребер: " << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "\tV" << vec[i].edge.first + 1 << " -> " << "V" << vec[i].edge.second + 1 << ": " << vec[i].value << endl;
        sum += vec[i].value;
    }
    cout << "\tСумма: " << sum;
}

void KruskalAlgorithm()
{
    struct PairValue
    {
        pair<int, int> edge;
        int value;
        int unionValue = -1;
    };

    vector<PairValue> vec;
    vector<int> unionCheck(V, -1);
    int visitedCheck[V][V] = { 0 };
    int edgeCount = 0;
    int unionCounter = 1;

    while (edgeCount != V - 1)
    {
        pair<int, int> minVert;
        int minValue = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adjacencyMatrix[i][j] > 0 && visitedCheck[i][j] != 1 && adjacencyMatrix[i][j] < minValue && (unionCheck[i] != unionCheck[j] || (unionCheck[i] == -1 && unionCheck[j] == -1)))
                {
                    minVert.first = i;
                    minVert.second = j;
                    minValue = adjacencyMatrix[i][j];
                }
            }
        }

        visitedCheck[minVert.first][minVert.second] = visitedCheck[minVert.second][minVert.first] = 1;

        vec.push_back({ {minVert.first, minVert.second}, minValue });

        if (unionCheck[minVert.first] == -1 && unionCheck[minVert.second] == -1)
        {
            unionCheck[minVert.first] = unionCounter;
            unionCheck[minVert.second] = unionCounter;
            unionCounter++;
        }
        else if (unionCheck[minVert.first] == -1)
        {
            unionCheck[minVert.first] = unionCheck[minVert.second];
        }
        else if (unionCheck[minVert.second] == -1)
        {
            unionCheck[minVert.second] = unionCheck[minVert.first];
        }
        else
        {
            int oldUnion = unionCheck[minVert.second];
            int newUnion = unionCheck[minVert.first];
            for (int k = 0; k < V; k++)
            {
                if (unionCheck[k] == oldUnion)
                {
                    unionCheck[k] = newUnion;
                }
            }
        }
        edgeCount++;
    }

    cout << "\n\n\tАлгоритм Крускала\n\tСписок ребер: " << endl;

    int sum = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "\tV" << vec[i].edge.first + 1 << " -> " << "V" << vec[i].edge.second + 1 << ": " << vec[i].value << endl;
        sum += vec[i].value;
    }
    cout << "\tСумма: " << sum;
}
