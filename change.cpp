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

   //сортировка монет, но лучше конечно просто sort
   int temp;
   std::vector<int> sortedCoins = coins;
   for(int i = 0;i<sortedCoins.size();i++)
   {
      for(int j = 0; j<sortedCoins.size();j++)
      {

         if(sortedCoins[i] > sortedCoins[j])
         {
            temp = sortedCoins[i];
            sortedCoins[i] = sortedCoins[j];
            sortedCoins[j] = temp;
         }
      }
    }


    int n = static_cast<int>(coins.size()); 
    res.clear();

    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i) {
        int r = C / sortedCoins[i];
        A[i] = r;
        C = C % sortedCoins[i];
    }
    
    if(C > 0)
    {
       cout << "Сдачу выдать невозможно";
       return false;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < A[i]; ++j)
            res.push_back(sortedCoins[i]);
    }

    return true; 
}
