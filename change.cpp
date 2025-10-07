#include "change.hpp"
#include <vector>
#include <algorithm>

constexpr int INF = 1'000'000'000;

bool changeM(int amount, const std::vector<Coin>& coins, std::vector<int>& res) 
{
    int amount1 = amount;

    // очищаем res, если вдруг будет повторное использование функции
    res.clear();

    // для случая если изначально сдача равна 0
    if (amount == 0)
        return true;

    // если сдача вдруг отрицательная
    if (amount < 0)
        return false;

    // фильтрация монет
    std::vector<Coin> filteredCoins;
    for (size_t i = 0; i < coins.size(); i++) {
        if (coins[i].m > 0 && coins[i].c > 0) {
            filteredCoins.push_back(coins[i]);
        }
    }

    // если нет нормальных монет, то нельзя с этим работать
    if (filteredCoins.empty())
        return false;

    // сортировка монет по убыванию номинала
    std::vector<Coin> sortedCoins = filteredCoins;
    std::sort(sortedCoins.begin(), sortedCoins.end(),
        [](const Coin& a, const Coin& b) {
            return a.m > b.m;
        });

    std::vector<int> A_gr(sortedCoins.size(), 0);

    for (int i = 0; i < sortedCoins.size(); ++i) {
        int r = amount / sortedCoins[i].m;

        if (sortedCoins[i].c < r) {
            A_gr[i] = sortedCoins[i].c;
            amount -= sortedCoins[i].m * sortedCoins[i].c;
        }

        if (sortedCoins[i].c >= r) {
            A_gr[i] = r;
            amount %= sortedCoins[i].m;
        }
    }
    // ответ после GR
    if (amount == 0) {
        for (int i = 0; i < sortedCoins.size(); ++i) {
            for (int j = 0; j < A_gr[i]; ++j)
                res.push_back(sortedCoins[i].m);
        }
        return true;
    }

    // считаем, сколько вообще денег у нас есть в монетах
    long long total = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i].m > 0 && coins[i].c > 0) {
            total += 1LL * coins[i].m * coins[i].c;
        }
    }

    // если всех монет вместе не хватает на сумму сразу false
    if (total < amount1)
        return false;

    // если жадный не справился
    if (amount > 0) {
        // массив для записи ответа
        std::vector<int> A(sortedCoins.size(), 0);
        std::vector<int> F(amount1 + 1, INF); // DP массив
        F[0] = 0; // начальное значение

        for (int i = 0; i < sortedCoins.size(); i++) {
            int coin = sortedCoins[i].m;
            int count = sortedCoins[i].c;
            for (int k = 1; count > 0; k <<= 1) {
                int use = std::min(k, count);
                for (int S = amount1; S >= use * coin; S--) {
                    if (F[S - use * coin] + use < F[S])
                        F[S] = F[S - use * coin] + use;
                }
                count -= use;
            }
        }

        // если невозможно выдать сдачу
        if (F[amount1] == INF)
            return false;

        // если решение есть,то восстанавливаем ответ
        while (amount1 != 0) {
            for (int i = 0; i < sortedCoins.size(); i++) {
                if (amount1 - sortedCoins[i].m >= 0 &&
                    (F[amount1] == (F[amount1 - sortedCoins[i].m] + 1)) &&
                    A[i] < sortedCoins[i].c) 
                {
                    A[i] += 1;
                    amount1 -= sortedCoins[i].m;
                    break;
                }
            }
        }

        // ответ после dp
        for (size_t i = 0; i < sortedCoins.size(); ++i) {
            for (int j = 0; j < A[i]; ++j)
                res.push_back(sortedCoins[i].m);
        }
        return true;
    }

    return false;
}
