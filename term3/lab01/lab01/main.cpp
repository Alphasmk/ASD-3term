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
		cout << "������� ���-�� ������: ";
		cin >> N;
		if (N < 1)
		{
			cout << "�������� ���������� ������" << endl;
		}
	} while (N < 1);
	do
	{
		do
		{
			cout << "������� ����� ���������� �������: ";
			cin >> i;
			if (i < 1 || i > 3)
			{
				cout << "�������� ���������� ��������" << endl;
			}
		} while (i < 1 || i > 3);
		do
		{
			cout << "������� ����� �������� �������: ";
			cin >> k;
			if (k < 1 || k > 3)
			{
				cout << "�������� ������� ��������" << endl;
			}
		} while (k < 1 || k > 3);
		if (i == k)
		{
			cout << "������� � ��������� �������� ���������" << endl;
		}
	} while (i == k);

	auto a = high_resolution_clock::now();
	tower(N, i, k);
	auto b = high_resolution_clock::now();
	auto time = duration_cast<milliseconds>(b - a);

	cout << "�����: " << time.count() << " ��" << endl;
	cout << "���������� �����: " << counter << endl;
}

void tower(int amount, int start, int end)
{
	counter++;
	if (amount == 1)
	{
		cout << "����������� ���� 1 c " << start << " �� " << end << " ��������." << endl << endl;
		return;
	}
	else
	{
		int buf = 6 - start - end;
		tower(amount - 1, start, buf);
		cout << "����������� ���� " << amount << " c " << start << " �� " << end << " ��������." << endl << endl;
		tower(amount - 1, buf, end);
	}
}