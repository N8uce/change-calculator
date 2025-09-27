#include "change.hpp"
#include <vector>
#include <iostream> 
using namespace std;

bool changeM(int C, const std::vector<int>& coins, std::vector<int>& res) 
{

    if (C == 0) 
    {
    res.clear();
    return false;
    }

    int n = static_cast<int>(coins.size()); 
    res.clear();

    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i) {
        int r = C / coins[i];
        A[i] = r;
        C = C % coins[i];
    }
    
    if(C > 0)
    {
       cout << "Сдачу выдать невозможно";
       return false;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < A[i]; ++j)
            res.push_back(coins[i]);
    }

    return true; 
}
