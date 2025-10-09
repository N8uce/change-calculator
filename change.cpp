#include "change.hpp"
#include "greedy_algorithm.hpp"
#include "dp_algorithm.hpp"
#include "utils.hpp"

bool MakeChange(int amount, const std::vector<Coin>& coins, std::vector<int>& resultCoins)
{
    resultCoins.clear();
    if (amount == 0) return true;
    if (amount < 0) return false;

    std::vector<Coin>filteredCoins = FilterValidCoins(coins);
    if (filteredCoins.empty()) return false;

    std::vector<Coin>sortedCoins = SortCoinsDescending(filteredCoins);

    std::vector<int> greedyResultCounts(sortedCoins.size(), 0);
    int greedyRemainder = GreedyAlgorithm(amount, sortedCoins, greedyResultCounts);

    if (greedyRemainder == 0) {
        AppendCoinsToResult(sortedCoins, greedyResultCounts, resultCoins);
        return true;
    }

    if (CalculateTotalValue(coins) < amount)
        return false;

    std::vector<int> dpResultCounts(sortedCoins.size(), 0);
    int dpRemainder = DynamicProgrammingAlgorithm(amount, sortedCoins, dpResultCounts);

    if (dpRemainder != 0)
        return false;

    AppendCoinsToResult(sortedCoins, dpResultCounts, resultCoins);
    return true;
}
