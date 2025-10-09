#pragma once
#include <vector>

struct Coin {
    int denomination; 
    int count; 
};

bool MakeChange(int amount, const std::vector<Coin>& coins, std::vector<int>& res);
