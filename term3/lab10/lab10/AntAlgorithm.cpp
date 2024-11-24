#include "AntAlgorithm.h"

double calculateProbability(int** matrix, int N, map<pair<int, int>, double> feromonesMap, int alpha, int beta, int i, int j, set<int> visited)
{
	double probability;
	double sum = 0;
	for (int k = 0; k < N; k++)
	{
		if (visited.count(k) == 0 && i != k)
		{
			sum += pow((1 / static_cast<double>(matrix[i][k])), beta) * pow(feromonesMap[make_pair(i, k)], alpha);
		}
	}

	probability = 100 * ((pow(1 / static_cast<double>(matrix[i][j]), beta) * pow(feromonesMap[make_pair(i, j)], alpha)) / sum);

	return probability;
}

void AntAlgorithm(int** matrix, int N, map<pair<int, int>, double> feromonesMap, int alpha, int beta, int iterations)
{
	int counter = 0;
	int vertexCounter = 0;
	set<int> visited;
	vector<Probability> probabilities;
	vector<pair<vector<int>, int>> ways;
	int i = 0;
	do
	{
		cout << "Итерация " << counter + 1 << ":\n";
		pair<vector<int>, int> way;
		i = 0;
		cout << "0";
		way.first.push_back(i);
		while(vertexCounter != N - 1)
		{
			visited.insert(i);
			vertexCounter++;
			for (int j = 0; j < N; j++)
			{
				if (visited.count(j) == 0)
				{
					double probability = calculateProbability(matrix, N, feromonesMap, alpha, beta, i, j, visited);
					probabilities.push_back({ { i, j }, probability });
				}
			}

			double choice = static_cast<double>(randNum(0, 100));

			double probabilitiesSum = 0;

			for (int k = 0; k < probabilities.size(); k++)
			{
				probabilitiesSum += probabilities[k].probability;
				if (probabilitiesSum > choice)
				{
					i = probabilities[k].indices.second;
					break;
				}
			}

			way.first.push_back(i);
			probabilities.clear();
		}
		int waySum = 0;
		for (int i = 1; i < way.first.size(); i++)
		{
			waySum += matrix[way.first[i]][way.first[i - 1]];
		}
		
		for (int i = 1; i < way.first.size(); i++)
		{
			feromonesMap[make_pair(way.first[i], way.first[i - 1])] = feromonesMap[make_pair(way.first[i], way.first[i - 1])] + feromonesMap[make_pair(way.first[i], way.first[i - 1])] / static_cast<double>(waySum);
			feromonesMap[make_pair(way.first[i - 1], way.first[i])] = feromonesMap[make_pair(way.first[i - 1], way.first[i])] + feromonesMap[make_pair(way.first[i - 1], way.first[i])] / static_cast<double>(waySum);
		}

		way.second = waySum;
		ways.push_back(way);

		sort(ways.begin(), ways.end(), [](const auto& a, const auto& b) {
			return a.second < b.second;
			});
		counter++;
		way.first.clear();
		vertexCounter = 0;
		visited.clear();
		for (int i = 1; i < ways[0].first.size(); i++)
		{
			cout << "->" << ways[0].first[i];
		}
		cout << "\nДлина пути: " << ways[0].second << "\n";
		cout << "\n";
		for (const auto& entry : feromonesMap) {
			const auto& key = entry.first;   // ключ (std::pair<int, int>)
			double value = entry.second;      // значение (double)

			std::cout << "Путь: (" << key.first << ", " << key.second << "), Значение феромона: " << value << std::endl;
		}
		cout << "\n\n";
	}while (counter != iterations);
}