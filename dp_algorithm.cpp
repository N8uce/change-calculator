#include "dp_algorithm.hpp"
#include <algorithm>

constexpr int INF = 1'000'000'000;

int DynamicProgrammingAlgorithm(int amount, const std::vector<Coin>& sortedCoins, std::vector<int>& resultCounts)
{
    std::vector<int> minCoinsForAmount(amount + 1, INF);
    minCoinsForAmount[0] = 0;

    for (const auto& coin : sortedCoins) {
        int coinValue = coin.denomination;
        int remainingCount = coin.count;

        for (int batch = 1; remainingCount > 0; batch <<= 1) {
            int used = std::min(batch, remainingCount);
            for (int sum = amount; sum >= used * coinValue; --sum) {
                if (minCoinsForAmount[sum - used * coinValue] + used < minCoinsForAmount[sum])
                    minCoinsForAmount[sum] = minCoinsForAmount[sum - used * coinValue] + used;
            }
            remainingCount -= used;
        }
    }

    if (minCoinsForAmount[amount] == INF)
        return amount;

    // восстановление решения
    while (amount > 0) {
        for (size_t i = 0; i < sortedCoins.size(); ++i) {
            int coinValue = sortedCoins[i].denomination;
            if (amount >= coinValue &&
                minCoinsForAmount[amount] == minCoinsForAmount[amount - coinValue] + 1 &&
                resultCounts[i] < sortedCoins[i].count) {
                resultCounts[i]++;
                amount -= coinValue;
                break;
            }
        }
    }

    return amount;
}
