#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>
using namespace std;

struct item
{
	string name;
	int weight;
	int price;
};

void searchItems(int**, vector<item>, int, int, vector<item>&);

int main()
{
	setlocale(LC_CTYPE, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введите максимальную вместимость рюкзака: ";
	cin >> N;

	vector<item> items;
	item buf;
	while (true)
	{
		char choice;

		cout << "\n1 - Добавить товар\n2 - Остановить ввод товаров\nВыберите вариант: ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "\nВведите название: ";
			cin >> buf.name;
			cout << "Введите цену: ";
			cin >> buf.price;
			cout << "Введите вес: ";
			cin >> buf.weight;
			items.push_back(buf);
			break;
		case '2':
			cout << "\n";
			break;
		default:
			cout << "Некорректный ввод";
		}
		if (choice == '2')
		{
			break;
		}
	}


	for (int i = 0; i < items.size(); i++)
	{
		cout << setw(3) << items[i].price << " ";
	}

	cout << "\n";
	
	for (int i = 0; i < items.size(); i++)
	{
		cout << setw(3) << items[i].weight << " ";
	}

	cout << "\n";

	int** table = new int* [items.size() + 1];
	for (int i = 0; i <= items.size(); i++)
	{
		table[i] = new int[N + 1]();
	}

	for (int k = 0; k <= items.size(); k++)
	{
		for (int s = 0; s <= N; s++)
		{
			if (k == 0 || s == 0)
			{
				table[k][s] = 0;
			}
			else
			{
				if (s >= items[k - 1].weight)
				{
					table[k][s] = max(table[k - 1][s], table[k - 1][s - items[k - 1].weight] + items[k - 1].price);
				}
				else
				{
					table[k][s] = table[k - 1][s];
				}
			}
		}
	}

	cout << setw(4) << "K\\S";
	for (int j = 0; j <= N; j++)
	{
		cout << setw(4) << j;
	}

	cout << "\n";

	for (int i = 0; i <= items.size(); i++)
	{
		cout << setw(4) << i;
		for (int j = 0; j <= N; j++)
		{
			cout << setw(4) << table[i][j];
		}
		cout << "\n\n";
	}

	cout << "\n";

	vector<item> result;

	searchItems(table, items, items.size(), N, result);
	for (int i = 0; i < result.size(); i++)
	{
		cout << i + 1 << ":\n" << "Название: " << result[i].name << "\nВес: " << result[i].weight << "\nЦена: " << result[i].price << "\n\n";
	}

	int price_sum = 0;
	int weight_sum = 0;

	for (int i = 0; i < result.size(); i++)
	{
		price_sum += result[i].price;
		weight_sum += result[i].weight;
	}

	cout << "\n" << "Итоговая суммарная стоимость предметов в рюкзаке: " << price_sum << "\n" << "Итоговый суммарный вес предметов в рюкзаке: " << weight_sum << "\n";

	for (int i = 0; i <= items.size(); i++)
	{
		delete[] table[i];
	}

	delete[] table;
}

void searchItems(int** table, vector<item> items, int k, int s, vector<item>& result)
{
	if (table[k][s] == 0 || k == 0 || s == 0)
	{
		return;
	}
	if (table[k - 1][s] == table[k][s])
	{
		searchItems(table, items, k - 1, s, result);
	}
	else
	{
		searchItems(table, items, k - 1, s - items[k - 1].weight, result);
		result.push_back(items[k - 1]);
	}
}