#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <Windows.h>
#include "MinNode.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите строку: " << endl;
    string str, result;
    getline(cin, str);

    multimap<int, char> freq = GetFrequency(str);

    MinNode* root = Huffman(freq);

    map<char, string> mp;
    GetCodes(root, "", mp);

    cout << "\nВыходная последовательность:\n" << ShowSequence(str, mp) << endl;

    cout << "\nДекодированная строка:\n" << DecodeSequence(ShowSequence(str, mp), root);
}