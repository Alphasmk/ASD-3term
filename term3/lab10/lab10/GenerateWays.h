#pragma once
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int randNum(int, int);
int** generateMatrix(int N);
map<pair<int, int>, double> generateWays(int**, int, double);