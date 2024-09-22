#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void tower(int amount, int start, int end);

int counter = 0;

int main()
{
	setlocale(LC_CTYPE, "rus");
	int N, k, i, buf{};
	do
	{
		cout << "Введите кол-во дисков: ";
		cin >> N;
		if (N < 1)
		{
			cout << "Неверное количество дисков" << endl;
		}
	} while (N < 1);
	do
	{
		do
		{
			cout << "Введите номер начального стержня: ";
			cin >> i;
			if (i < 1 || i > 3)
			{
				cout << "Неверный начального стержень" << endl;
			}
		} while (i < 1 || i > 3);
		do
		{
			cout << "Введите номер целового стержня: ";
			cin >> k;
			if (k < 1 || k > 3)
			{
				cout << "Неверный целовой стержень" << endl;
			}
		} while (k < 1 || k > 3);
		if (i == k)
		{
			cout << "Целевой и начальный стержень совпадают" << endl;
		}
	} while (i == k);

	auto a = high_resolution_clock::now();
	tower(N, i, k);
	auto b = high_resolution_clock::now();
	auto time = duration_cast<milliseconds>(b - a);

	cout << "Время: " << time.count() << " мс" << endl;
	cout << "Количество ходов: " << counter << endl;
}

void tower(int amount, int start, int end)
{
	counter++;
	if (amount == 1)
	{
		cout << "Переместить диск 1 c " << start << " на " << end << " стержень." << endl << endl;
		return;
	}
	else
	{
		int buf = 6 - start - end;
		tower(amount - 1, start, buf);
		cout << "Переместить диск " << amount << " c " << start << " на " << end << " стержень." << endl << endl;
		tower(amount - 1, buf, end);
	}
}