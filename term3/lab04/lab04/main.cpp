#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const int msize = 6;

void FloydsAlgorithm(int(&sw)[msize][msize], int(&sq)[msize][msize]);
void PrintWay(int(&sw)[msize][msize], int(&sq)[msize][msize], int start, int end);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int shortesWayMatrix[msize][msize]
	{
		{0, 28, 21, 59, 12, 27},
		{7, 0, 24, INT_MAX, 21, 9},
		{9, 32, 0, 13, 11, INT_MAX},
		{8, INT_MAX, 5, 0, 16, INT_MAX},
		{14, 13, 15, 10, 0, 22},
		{15, 18, INT_MAX, INT_MAX, 6, 0}
	};

	int sequenceMatrix[msize][msize]
	{
		{0, 2, 3, 4, 5, 6},
		{1, 0, 3, 4, 5, 6},
		{1, 2, 0, 4, 5, 6},
		{1, 2, 3, 0, 5, 6},
		{1, 2, 3, 4, 0, 6},
		{1, 2, 3, 4, 5, 0}
	};

	FloydsAlgorithm(shortesWayMatrix, sequenceMatrix);

	int start, end;
	cout << "Введите начало (1-" << msize << "): ";
	cin >> start;

	cout << "Введите конец (1-" << msize << "): ";
	cin >> end;

	start -= 1;
	end -= 1;

	if (start < 0 || start >= msize || end < 0 || end >= msize) {
		cout << "Неверные значения начала или конца." << endl;
		return 1;
	}

	PrintWay(shortesWayMatrix, sequenceMatrix, start, end);
	cout << endl;

	return 0;
}

void FloydsAlgorithm(int(&sw)[msize][msize], int(&sq)[msize][msize])
{
	for (int v = 0; v < msize; v++)
	{
		for (int a = 0; a < msize; a++)
		{
			for (int b = 0; b < msize; b++)
			{
				if (sw[a][v] != INT_MAX && sw[v][b] != INT_MAX)
				{
					if (sw[a][b] > sw[a][v] + sw[v][b])
					{
						sw[a][b] = sw[a][v] + sw[v][b];
						sq[a][b] = sq[a][v];
					}
				}
			}
		}
	}
}

void PrintWay(int(&sw)[msize][msize], int(&sq)[msize][msize], int start, int end)
{
	if (sw[start][end] == INT_MAX)
	{
		cout << "Нет пути между " << start + 1 << " и " << end + 1 << endl;
		return;
	}

	cout << "Кратчайший путь: " << start + 1;
	int totalLength = sw[start][end];

	while (start != end)
	{
		start = sq[start][end] - 1;
		cout << " -> " << start + 1;
	}

	cout << endl << "Длина пути: " << totalLength << endl << endl << "Матрица крaтчайших путей: " << endl;

	for (int i = 0; i < msize; i++)
	{
		for (int j = 0; j < msize; j++)
		{
			cout << setw(3) << sw[i][j];
		}
		cout << endl;
	}

	cout << endl << "Матрица последовательности вершин: " << endl;

	for (int i = 0; i < msize; i++)
	{
		for (int j = 0; j < msize; j++)
		{
			cout << setw(3) << sq[i][j];
		}
		cout << endl;
	}
}