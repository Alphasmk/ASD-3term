#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

void adjacencyMatrix1(queue<int>& q);
void adjacencyList1(queue<int>& q);
void pList1(queue<int>& q);
void adjacencyMatrix2(stack<int>& q);
void adjacencyList2(stack<int>& q);
void pList2(stack<int>& q);

bool visitedA[10] = { false };
bool visitedB[10] = { false };
bool visitedC[10] = { false };
bool visitedD[10] = { false };
bool visitedE[10] = { false };
bool visitedF[10] = { false };

int matrix[10][10] = {
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

vector<vector<int>> list = {
    {2, 5},
    {1, 7, 8},
    {8},
    {6, 9},
    {1, 6},
    {4, 9},
    {2, 8},
    {2, 3, 7},
    {4, 6, 10},
    {9}
};

vector<pair<int, int>> pairList =
{
    {1, 2},
    {2, 7},
    {2, 8},
    {1, 5},
    {5, 6},
    {7, 8},
    {8, 3},
    {6, 4},
    {4, 9},
    {9, 6},
    {9, 10}
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    cout << "BFS: " << endl;
    cout << "Матрица смежности: ";
    queue<int> q1;
    int index = 1;
    q1.push(index);
    visitedA[index - 1] = true;
    cout << "{" << index;
    adjacencyMatrix1(q1);
    cout << "}" << endl;

    cout << "Список смежности: ";
    queue<int> q2;
    index = 1;
    q2.push(index);
    cout << "{" << index;
    adjacencyList1(q2);
    cout << "}" << endl;

    cout << "Список рёбер: ";
    queue<int> q3;
    index = 1;
    q3.push(index);
    cout << "{" << index;
    pList1(q3);
    cout << "}";

    cout << endl << "DFS: " << endl;

    cout << "Матрица смежности: ";
    stack<int> s1;
    index = 1;
    s1.push(index);
    visitedD[index - 1] = true;
    cout << "{" << index;
    adjacencyMatrix2(s1);
    cout << "}" << endl;

    cout << "Список смежности: ";
    stack<int> s2;
    index = 1;
    s2.push(index);
    cout << "{" << index;
    adjacencyList2(s2);
    cout << "}" << endl;

    cout << "Список рёбер: ";
    stack<int> s3;
    index = 1;
    s3.push(index);
    cout << "{" << index;
    pList2(s3);
    cout << "}" << endl;
    cout << "О - большое: " << endl;
    cout << "Матрица смежности: " << 10 * 10 << endl;
    cout << "Список ребер: " << list.size() + 1 + 10 << endl;
    cout << "Список смежности: " << list.size() + 1 + 10 << endl;
}

void adjacencyMatrix1(queue<int>& q)
{
    while (!q.empty())
    {
        int index = q.front();
        q.pop();

        for (int i = 0; i < 10; i++)
        {
            if (matrix[index - 1][i] == 1 && !visitedA[i]) 
            {
                q.push(i + 1); 
                visitedA[i] = true; 
                cout << ", " << i + 1;
            }
        }
    }
}

void adjacencyList1(queue<int>& q)
{
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        if (!visitedB[index - 1])
        {
            if (index != 1)
            {
                cout << ", " << index ;
            }
            visitedB[index - 1] = true;
            for (int i = 0; i < list[index - 1].size(); i++)
            {
                q.push(list[index - 1][i]);
            }
        }
    }
}

void pList1(queue<int>& q)
{
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        if (!visitedC[index - 1])
        {
            if (index != 1)
            {
                cout << ", " << index;
            }
            visitedC[index - 1] = true;
            for (int i = 0; i < pairList.size(); i++)
            {
                if (pairList[i].first == index)
                {
                    q.push(pairList[i].second);
                }
                else if (pairList[i].second == index)
                {
                    q.push(pairList[i].first);
                }
            }
        }
    }
}

void adjacencyMatrix2(stack<int>& s)
{
    while (!s.empty())
    {
        int index = s.top();
        s.pop();

        for (int i = 0; i < 10; i++)
        {
            if (matrix[index - 1][i] == 1 && !visitedD[i])
            {
                s.push(i + 1);
                visitedD[i] = true;
                cout << ", " << i + 1;
            }
        }
    }
}

void adjacencyList2(stack<int>& s)
{
    while (!s.empty())
    {
        int index = s.top();
        s.pop();
        if (!visitedE[index - 1])
        {
            if (index != 1)
            {
                cout << ", " << index;
            }
            visitedE[index - 1] = true;
            for (int i = 0; i < list[index - 1].size(); i++)
            {
                s.push(list[index - 1][i]);
            }
        }
    }
}

void pList2(stack<int>& s)
{
    while (!s.empty())
    {
        int index = s.top();
        s.pop();
        if (!visitedF[index - 1])
        {
            if (index != 1)
            {
                cout << ", " << index;
            }
            visitedF[index - 1] = true;
            for (int i = 0; i < pairList.size(); i++)
            {
                if (pairList[i].first == index)
                {
                    s.push(pairList[i].second);
                }
                else if (pairList[i].second == index)
                {
                    s.push(pairList[i].first);
                }
            }
        }
    }
}