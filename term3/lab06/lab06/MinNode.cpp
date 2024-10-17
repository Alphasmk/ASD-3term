#include "MinNode.h"
#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <Windows.h>
using namespace std;

multimap<int, char> GetFrequency(string str)
{
    map<char, int> freq;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
    }

    multimap<int, char> frequency = sortMap(freq);

    cout << "Таблица встречаемости символов (символ - количество):" << endl;
    for (auto& it : frequency)
    {
        cout << "\t\t" << it.second << ": " << it.first << endl;
    }
    return frequency;
}

multimap<int, char> sortMap(map<char, int>& M)
{
    multimap<int, char> MM;

    for (auto& it : M)
    {
        MM.insert({ it.second, it.first });
    }
    return MM;
}

map<char, string> GetCodes(class MinNode* root, string str, map<char, string>& mp)
{
    if (!root)
        return mp;

    if (root->data != '$')
    {
        mp[root->data] = str;
        cout << "\t\t" << root->data << ": " << str << "\n";
    }

    GetCodes(root->left, str + "0", mp);
    GetCodes(root->right, str + "1", mp);

    return mp;
}

MinNode* Huffman(multimap<int, char> freq)
{
    MinNode* left, * right, * top;

    priority_queue<MinNode*, vector<MinNode*>, compare> minHeap;

    // Добавляем символы в очередь
    for (auto& it : freq)
        minHeap.push(new MinNode(it.second, it.first));

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    return minHeap.top();
}

string ShowSequence(string src, map<char, string> mp)
{
    string result;
    for (unsigned int i = 0; i < src.length(); i++)
    {
        result.append(mp[src[i]]);
    }
    return result;
}

string DecodeSequence(string encodedStr, MinNode* root)
{
    string result = "";
    MinNode* current = root;

    for (unsigned int i = 0; i < encodedStr.length(); i++)
    {
        if (encodedStr[i] == '0')
            current = current->left;
        else
            current = current->right;

        if (current->left == nullptr && current->right == nullptr)
        {
            result += current->data;
            current = root;
        }
    }

    return result;
}
