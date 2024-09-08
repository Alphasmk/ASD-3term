#include <iostream>
using namespace std;

void tower(int amount, int start, int end);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int N, k, i, buf{};
	cout << "Введите кол-во дисков: ";
	cin >> N;
	do
	{
		cout << "Введите номер начального стержня: ";
		cin >> i;
		if (i < 1 || i > 3)
		{
			cout << "Неверный целовой стержень" << endl;
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
	tower(N, i, k);
}

void tower(int amount, int start, int end)
{

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