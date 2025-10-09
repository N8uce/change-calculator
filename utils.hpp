#pragma once
#include <vector>
#include "change.hpp"

void AppendCoinsToResult(const std::vector<Coin>& sortedCoins, const std::vector<int>& resultCounts, std::vector<int>& resultCoins);

std::vector<Coin> FilterValidCoins(const std::vector<Coin>& coins);

std::vector<Coin> SortCoinsDescending(const std::vector<Coin>& coins);

long long CalculateTotalValue(const std::vector<Coin>& coins);
