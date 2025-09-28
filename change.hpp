#pragma once
#include <vector>

struct Coin {
    int m; 
    int c; 
};

bool changeM(int C, const std::vector<Coin>& coins, std::vector<int>& res);