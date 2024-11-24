#include "evolution.h"

vector<pair<vector<int>, int>> evolution(vector<vector<int>> matrix, vector<pair<vector<int>, int>> population, int evolutionCount, int mutationChance)
{
	int count = 0;
	do
	{
		int firstParent, secondParent;
		do
		{
			firstParent = rand() % population.size();
			secondParent = rand() % population.size();
		} while (firstParent == secondParent);
		int breakPoint = population[firstParent].first.size() / 2;
		vector<int> firstDescendant;
		vector<int> inheriteGenes;
		for (int i = 0; i < breakPoint; i++)
		{
			firstDescendant.push_back(population[firstParent].first[i]);
			inheriteGenes.push_back(population[firstParent].first[i]);
		}
		for (int i = breakPoint; i < population[firstParent].first.size(); i++)
		{
			bool isGoodGene = true;
			for (int j = 0; j < inheriteGenes.size(); j++)
			{
				if (inheriteGenes[j] == population[secondParent].first[i])
				{
					isGoodGene = false;
				}
			}
			if (isGoodGene)
			{
				firstDescendant.push_back(population[secondParent].first[i]);
				inheriteGenes.push_back(population[secondParent].first[i]);
			}
		}
		if (firstDescendant.size() != population[firstParent].first.size())
		{
			for (int i = breakPoint; i < population[firstParent].first.size(); i++)
			{
				bool isGoodGene = true;
				for (int j = 0; j < inheriteGenes.size(); j++)
				{
					if (inheriteGenes[j] == population[firstParent].first[i])
					{
						isGoodGene = false;
					}
				}
				if (isGoodGene)
				{
					firstDescendant.push_back(population[firstParent].first[i]);
					inheriteGenes.push_back(population[firstParent].first[i]);
				}
			}
		}

		vector<int> secondDescendant;
		inheriteGenes.clear();
		for (int i = 0; i < breakPoint; i++)
		{
			secondDescendant.push_back(population[secondParent].first[i]);
			inheriteGenes.push_back(population[secondParent].first[i]);
		}
		for (int i = breakPoint; i < population[secondParent].first.size(); i++)
		{
			bool isGoodGene = true;
			for (int j = 0; j < inheriteGenes.size(); j++)
			{
				if (inheriteGenes[j] == population[firstParent].first[i])
				{
					isGoodGene = false;
				}
			}
			if (isGoodGene)
			{
				secondDescendant.push_back(population[firstParent].first[i]);
				inheriteGenes.push_back(population[firstParent].first[i]);
			}
		}
		for (int i = breakPoint; i < population[secondParent].first.size(); i++)
		{
			bool isGoodGene = true;
			for (int j = 0; j < inheriteGenes.size(); j++)
			{
				if (inheriteGenes[j] == population[secondParent].first[i])
				{
					isGoodGene = false;
				}
			}
			if (isGoodGene)
			{
				secondDescendant.push_back(population[secondParent].first[i]);
				inheriteGenes.push_back(population[secondParent].first[i]);
			}
		}

		firstDescendant = mutate(firstDescendant, mutationChance);
		secondDescendant = mutate(secondDescendant, mutationChance);

		int size1 = 0, size2 = 0;
		for (int i = 1; i < firstDescendant.size(); i++)
		{
			size1 += matrix[firstDescendant[i]][firstDescendant[i - 1]];
		}

		for (int i = 1; i < secondDescendant.size(); i++)
		{
			size2 += matrix[secondDescendant[i]][secondDescendant[i - 1]];
		}

		population.push_back({ firstDescendant, size1 });
		population.push_back({ secondDescendant, size2 });
		sort(population.begin(), population.end(), []
		(const auto& a, const auto& b)
			{
				return a.second < b.second;
			}
		);
		population.pop_back();
		population.pop_back();
		count++;
		cout << "Эволюция " << count << ":\n" << "Кратчайший путь: ";
		cout << population[0].first[0];

		for (int i = 1; i < population[0].first.size(); i++)
		{
			cout << " -> " << population[0].first[i];
		}

		cout << "\n" << "Длина пути: " << population[0].second << "\n\n";
		
	}while (count < evolutionCount);
	return population;
}
