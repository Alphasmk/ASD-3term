#include <iostream>
#include <utility>
#include <map>
#include "GenerateWays.h"
#include "AntAlgorithm.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	srand(time(0));
	int N;
	do
	{
		cout << "¬ведите количество городов(минимальное - 3): ";
		cin >> N;
	} while (N <= 2);

	double feromons;
	do
	{
		cout << "¬ведите начальное значение феромонов на каждом ребре графа: ";
		cin >> feromons;
	} while (feromons < 1);

	int alpha, beta;
	do
	{
		cout << "¬ведите значение alpha и beta: ";
		cin >> alpha >> beta;
	} while (alpha < 0 || beta < 0);

	int iterations;
	do
	{
		cout << "¬ведите количество итераций: ";
		cin >> iterations;
	} while (iterations < 3);

	int** matrix;
	matrix = generateMatrix(N);
	map<pair<int, int>, double> feromonesMap = generateWays(matrix, N, feromons);

	AntAlgorithm(matrix, N, feromonesMap, alpha, beta, iterations);

	for (int i = 0; i < N; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}