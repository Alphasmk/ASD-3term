#include <iostream>
using namespace std;

void tower(int amount, int start, int end);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int N, k, i, buf{};
	cout << "������� ���-�� ������: ";
	cin >> N;
	do
	{
		cout << "������� ����� ���������� �������: ";
		cin >> i;
		if (i < 1 || i > 3)
		{
			cout << "�������� ������� ��������" << endl;
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
	tower(N, i, k);
}

void tower(int amount, int start, int end)
{

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