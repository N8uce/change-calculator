#include "utils.hpp"
#include <algorithm>

void AppendCoinsToResult(const std::vector<Coin>& sortedCoins, const std::vector<int>& resultCounts, std::vector<int>& resultCoins)
{
    for (size_t i = 0; i < sortedCoins.size(); ++i) {
        for (int j = 0; j < resultCounts[i]; ++j)
            resultCoins.push_back(sortedCoins[i].denomination);
    }
}

std::vector<Coin> FilterValidCoins(const std::vector<Coin>& coins)
{
    std::vector<Coin> filtered;
    for (const auto& coin : coins) {
        if (coin.denomination > 0 && coin.count > 0)
            filtered.push_back(coin);
    }
    return filtered;
}

std::vector<Coin> SortCoinsDescending(const std::vector<Coin>& coins)
{
    std::vector<Coin> sorted = coins;
    std::sort(sorted.begin(), sorted.end(), [](const Coin& a, const Coin& b) {
        return a.denomination > b.denomination;
    });
    return sorted;
}

long long CalculateTotalValue(const std::vector<Coin>& coins)
{
    long long total = 0;
    for (const auto& coin : coins)
        total += 1LL * coin.denomination * coin.count;
    return total;
}
