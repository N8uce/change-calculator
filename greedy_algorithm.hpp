#pragma once
#include <vector>
#include "change.hpp"

//функция с реализацией жадного алгоритма подбора монет
int GreedyAlgorithm(int amount, const std::vector<Coin>& sortedCoins, std::vector<int>& resultCounts);
