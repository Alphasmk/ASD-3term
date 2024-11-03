#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    vector<int> vec;
    int choice;

    while (true)
    {
        cout << "Введите число последовательности(-1 чтобы остановить): ";
        cin >> choice;
        if (choice != -1)
        {
            vec.push_back(choice);
        }
        else
        {
            break;
        }
    }

    if (vec.empty()) {
        cout << "Последовательность пуста." << endl;
        return 0;
    }

    vector<int> length(vec.size(), 1);
    vector<int> predecessor(vec.size(), -1);

    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] < vec[i])
            {
                if (length[j] + 1 >= length[i])
                {
                    length[i] = length[j] + 1;
                    predecessor[i] = j;
                }
            }
        }
    }

    int maxLength = 0;
    for (int i = 1; i < length.size(); i++)
    {
        if (length[i] > length[maxLength])
        {
            maxLength = i;
        }
    }

    vector<int> lis;
    for (int i = maxLength; i != -1; i = predecessor[i])
    {
        lis.push_back(vec[i]);
    }

    cout << "Размер подпоследовательности: " << lis.size() << endl;

    cout << "Наибольшая возрастающая подпоследовательность: ";
    for (int i = lis.size() - 1; i >= 0; i--)
    {
        cout << lis[i] << " ";
    }
    cout << endl;

    return 0;
}