#include "greedy_algorithm.hpp"

int GreedyAlgorithm(int amount, const std::vector<Coin>& sortedCoins, std::vector<int>& resultCounts)
{
    for (size_t i = 0; i < sortedCoins.size(); ++i) {
        int maxUsable = amount / sortedCoins[i].denomination;

        if (sortedCoins[i].count < maxUsable) {
            resultCounts[i] = sortedCoins[i].count;
            amount -= sortedCoins[i].denomination * sortedCoins[i].count;
        } else {
            resultCounts[i] = maxUsable;
            amount %= sortedCoins[i].denomination;
        }
    }
    return amount;
}
