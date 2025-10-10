#include "change.hpp"
#include "greedy_algorithm.hpp"
#include "dp_algorithm.hpp"
#include "utils.hpp"

bool MakeChange(int amount, const std::vector<Coin>& coins, std::vector<int>& resultCoins)
{
    //если вдруг будут повторные использования функции
    resultCoins.clear();

    //для случая если изначально сдача равна 0
    if (amount == 0)
        return true;

    //сдача отрицательная
    if (amount < 0) 
        return false;

    //фильтрация монет
    std::vector<Coin>filteredCoins = FilterValidCoins(coins);

    //если все монеты, не валидные
    if (filteredCoins.empty()) 
        return false;

    //сортировка монет по убыванию номинала
    std::vector<Coin>sortedCoins = SortCoinsDescending(filteredCoins);

    

    //жадный алгоритм
    std::vector<int> greedyResultCounts(sortedCoins.size(), 0);//массив ответа GR
    int greedyRemainder = GreedyAlgorithm(amount, sortedCoins, greedyResultCounts);

    //если сдача нулевая после жадного, записываем ответ
    if (greedyRemainder == 0) {
        AppendCoinsToResult(sortedCoins, greedyResultCounts, resultCoins);
        return true;
    }
    
    //если жадный не выдаст true, дальше пойдёт DP часть

    //если сумма монеток меньше сдачи, сдачу выдать невозможно
    if (CalculateTotalValue(coins) < amount)
        return false;

    std::vector<int> dpResultCounts(sortedCoins.size(), 0);//массив ответа DP
    int dpRemainder = DynamicProgrammingAlgorithm(amount, sortedCoins, dpResultCounts);
    
    //если сдача от DP ненулевая, то сдачу выдать нельзя
    if (dpRemainder != 0)
        return false;

    //если это условие проходит, записываем ответ, и выдаём сдачу
    AppendCoinsToResult(sortedCoins, dpResultCounts, resultCoins);
    return true;
}
