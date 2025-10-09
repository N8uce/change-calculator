#pragma once
#include <vector>
#include "change.hpp"

//функция с реализацией алгоритма динамического программирования
int DynamicProgrammingAlgorithm(int amount, const std::vector<Coin>& sortedCoins, std::vector<int>& resultCounts);
