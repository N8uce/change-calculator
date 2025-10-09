#pragma once
#include <vector>
#include "change.hpp"

//добавляет номиналы монет в результирующий вектор
void AppendCoinsToResult(const std::vector<Coin>& sortedCoins, const std::vector<int>& resultCounts, std::vector<int>& resultCoins);

//фильтрует список монет, исключая недопустимые значения
std::vector<Coin> FilterValidCoins(const std::vector<Coin>& coins);

//сортирует монеты по убыванию номинала
std::vector<Coin> SortCoinsDescending(const std::vector<Coin>& coins);

//подсчитывает общую сумму денег во всех монетах
long long CalculateTotalValue(const std::vector<Coin>& coins);
