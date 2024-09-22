#include <iostream>
#include <queue>
using namespace std;

void DijkstraAlgorithm(int, char);

int matrix[9][9] =
{
	{0, 7, 10, 0, 0, 0, 0, 0, 0},
	{7, 0, 0, 0, 0, 9, 27, 0, 0},
	{10, 0, 0, 0, 31, 8, 0, 0, 0},
	{0, 0, 0, 0, 32, 0, 0, 17, 21},
	{0, 0, 31, 32, 0, 0, 0, 0, 0},
	{0, 9, 8, 0, 0, 0, 0, 11, 0},
	{0, 27, 0, 0, 0, 0, 0, 0, 15},
	{0, 0, 0, 17, 0, 11, 0, 0, 15},
	{0, 0, 0, 21, 0, 0, 15, 15, 0}
};

int main()
{
	setlocale(LC_CTYPE, "rus");

	char startIndex;
	do
	{
		cout << "Введите стартовую вершину (A-I): ";
		cin >> startIndex;
		if (startIndex < 'A' || startIndex > 'I') {
			cout << "Введите букву от A до I" << endl;
		}
	} while (startIndex < 'A' || startIndex > 'I');

    int start = static_cast<int>(startIndex - 'A');
	cout << "Стартовая вершина - " << startIndex << endl;
	DijkstraAlgorithm(start, startIndex);
}

void DijkstraAlgorithm(int start, char outSymb)
{
	bool isVisited[9] = { false };
	int result[9] = { 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000 };
	int counter = 0;
	result[start] = 0;

	do
	{
		for (int i = 0; i < 9; i++)
		{
			if (matrix[start][i] != 0 && !isVisited[i] && result[start] + matrix[start][i] < result[i])
			{
				result[i] = result[start] + matrix[start][i];
			}
		}

		isVisited[start] = true;
		int min = 10000;
		int nextVer = -1;

		for (int i = 0; i < 9; i++)
		{
			if (!isVisited[i] && result[i] < min)
			{
				min = result[i];
				nextVer = i;
			}
		}

		if (nextVer == -1)
		{
			break;
		}

		start = nextVer;
		counter++;
	} while (true);

	for (int i = 0; i < 9; i++)
	{
		cout << outSymb << " - " << static_cast<char>(static_cast<int>('A' + i)) << " -> " << result[i] << endl;
	}
}
