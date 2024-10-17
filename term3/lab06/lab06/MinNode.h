#pragma once
#include <iostream>
#include <queue>
#include <map>
#include <Windows.h>
#include <string>
using namespace std;

map<char, string> GetCodes(class MinNode* root, string str, map<char, string>& mp);
MinNode* Huffman(multimap<int, char> freq);
multimap<int, char> GetFrequency(string str);
multimap<int, char> sortMap(map<char, int>& M);
string ShowSequence(string src, map<char, string> mp);
string DecodeSequence(string encodedStr, MinNode* root);

class MinNode
{
public:
    char data;

    unsigned freq;

    MinNode* left, * right;

    MinNode(char data, unsigned freq)
    {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(MinNode* l, MinNode* r)
    {
        if (l->freq == r->freq)
            return (int)l->data < (int)r->data; // Дополнительное сравнение по символу
        return l->freq > r->freq;
    }
};