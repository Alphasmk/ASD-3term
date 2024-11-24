#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#include <string>
#include "generatePapulation.h"
#include "evolution.h"
using namespace std;

const int INF = 1000000;

void printMatrix(const vector<vector<int>>& matrix) {
	for (const auto& row : matrix) {
		for (const auto& elem : row) {
			cout << setw(5) << (elem == INF ? "INF" : to_string(elem)) << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void addCity(vector<vector<int>>& matrix) {
	int newSize = matrix.size() + 1;
	for (auto& row : matrix) {
		row.push_back(INF);
	}
	matrix.push_back(vector<int>(newSize, INF));
	cout << "����� ��������. ������� �������:\n";
	printMatrix(matrix);
}

void removeCity(vector<vector<int>>& matrix, int city) {
	if (city < 0 || city >= matrix.size()) {
		cout << "������������ ������ ������.\n";
		return;
	}
	matrix.erase(matrix.begin() + city);
	for (auto& row : matrix) {
		row.erase(row.begin() + city);
	}
	cout << "����� �����. ������� �������:\n";
	printMatrix(matrix);
}

void addRoad(vector<vector<int>>& matrix, int from, int to, int weight) {
	if (from < 0 || from >= matrix.size() || to < 0 || to >= matrix.size() || from == to) {
		cout << "������������ ������� �������.\n";
		return;
	}
	matrix[from][to] = weight;
	matrix[to][from] = weight;
	cout << "������ ���������. ������� �������:\n";
	printMatrix(matrix);
}

void removeRoad(vector<vector<int>>& matrix, int from, int to) {
	if (from < 0 || from >= matrix.size() || to < 0 || to >= matrix.size() || from == to || matrix[from][to] == INF || matrix[to][from] == INF) {
		cout << "������������ ������� �������.\n";
		return;
	}
	matrix[from][to] = INF;
	matrix[to][from] = INF;
	cout << "������ �������. ������� �������:\n";
	printMatrix(matrix);
}

int main()
{
	srand(time(0));
	setlocale(LC_CTYPE, "rus");
	vector<vector<int>> matrix;
	matrix.push_back({ INF, 10, 3, 10, 9, 19, 21, 14 });
	matrix.push_back({ 10, INF, 19, 15, 6, 8, 12, 8 });
	matrix.push_back({ 3, 19, INF, 4, 19, 5, 18, 11 });
	matrix.push_back({ 10, 15, 4, INF, 3, 12, 9, 11 });
	matrix.push_back({ 9, 6, 19, 3, INF, 17, 4, 14 });
	matrix.push_back({ 19, 8, 5, 12, 17, INF, 8, 6 });
	matrix.push_back({ 21, 12, 18, 9, 4, 8, INF, 11 });
	matrix.push_back({ 14, 8, 11, 11, 14, 6, 11, INF });

	char ch;
	vector<pair<vector<int>, int>> population;
	int infCounter;
	do {
		cout << "����:\n"
			<< "1. �������� �����\n"
			<< "2. ������� �����\n"
			<< "3. �������� ������\n"
			<< "4. ������� ������\n"
			<< "5. �������� �������\n"
			<< "6. ������ ���������� ���������\n"
			<< "��� �����: ";
		cin >> ch;

		switch (ch) {
		case '1':
			addCity(matrix);
			break;
		case '2': {
			int city;
			cout << "������� ������ ������ ��� ��������: ";
			cin >> city;
			removeCity(matrix, city);
			break;
		}
		case '3': {
			int from, to, weight;
			cout << "������� ������ (������ � ����) � ��� ������ (��������, 0 1 10): ";
			cin >> from >> to >> weight;
			addRoad(matrix, from, to, weight);
			break;
		}
		case '4': {
			int from, to;
			cout << "������� ������ (������ � ����) ��� �������� ������ (��������, 0 1): ";
			cin >> from >> to;
			removeRoad(matrix, from, to);
			break;
		}
		case '5':
			cout << "������� ������� ���������:\n";
			printMatrix(matrix);
			break;
		case '6':

			infCounter = 0;
			for (int i = 0; i < matrix.size(); i++)
			{
				for (int j = 0; j < matrix.size(); j++)
				{
					if (matrix[i][j] == INF)
					{
						infCounter++;
					}
				}
			}

			if (infCounter <= matrix.size())
			{
				int choice;
				do
				{
					cout << "������� ������ ���������: ";
					cin >> choice;
					if (choice < matrix.size())
					{
						cout << "������ ��������� �� ����� ���� ������ ����� �������(" << matrix.size() << ")\n";
					}
				} while (choice < matrix.size());

				population = generatePopulation(matrix, choice);

				int mutationChance, evolutionCount;

				do
				{
					cout << "������� ���-�� ��������(������� 5): ";
					cin >> evolutionCount;
					cout << "������� ������� �������(������� 10%): ";
					cin >> mutationChance;
					if (evolutionCount < 5 || mutationChance < 10)
					{
						cout << "�������� ��������";
					}
				} while (evolutionCount < 5 || mutationChance < 10);

				population = evolution(matrix, population, evolutionCount, mutationChance);
				infCounter = 0;
				break;

			}
			else
			{
				cout << "�� ������� ������ ������ ���� ������ � �������\n";
				infCounter = 0;
			}
		default:
			cout << "������������ �����.\n";
		}
	} while (ch != 6);

}
