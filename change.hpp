#pragma once
#include <vector>

struct Coin {
    int denomination; //номинал
    int count; //кол-во
};
//Функция проверяет, можно ли выдать сдачу на сумму amount с имеющимися монетами и, если возможно, 
//возвращает конкретный набор монет, который даёт эту сумму.
bool MakeChange(int amount, const std::vector<Coin>& coins, std::vector<int>& res);
