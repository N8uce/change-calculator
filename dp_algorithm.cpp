#include "dp_algorithm.hpp"
#include <algorithm>

constexpr int INF = 1'000'000'000;

int DynamicProgrammingAlgorithm(int amount, const std::vector<Coin>& sortedCoins, std::vector<int>& resultCounts)
{
    //массив для DP
    std::vector<int> minCoinsForAmount(amount + 1, INF);
    minCoinsForAmount[0] = 0;

    for (int i = 0; i < sortedCoins.size(); i++) {
        int coin = sortedCoins[i].m;   //номинал монеты
        int count = sortedCoins[i].c;  //количество монет

        for (int k = 1; k <= count; k++) { 
            for (int S = amount; S >= coin; S--) {
                if (F[S - coin] + 1 < F[S])
                    F[S] = F[S - coin] + 1;
            }
        }
    }

    // если алгоритм не нашёл комбинацию, то он завершается
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
