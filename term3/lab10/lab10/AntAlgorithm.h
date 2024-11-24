#pragma once
#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
#include <set>
#include <vector>
#include "GenerateWays.h"
#include <algorithm>
using namespace std;

struct Probability {
    pair<int, int> indices;
    double probability;
};

double calculateProbability(int** matrix, int N, map<pair<int, int>, double> feromonesMap, int alpha, int beta, int i, int j, set<int> visited);
void AntAlgorithm(int** matrix, int N, map<pair<int, int>, double> feromonesMap, int alpha, int beta, int iterations);