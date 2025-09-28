#include "change.hpp"
#include <vector>
#include <iostream> 

bool changeM(int C, const std::vector<Coin>& coins, std::vector<int>& res) 
{

    if (C == 0) 
    {
    res.clear();
    return true;
    }

   //сортировка монет, но лучше конечно просто sort
   int temp;
   int temp1;
   std::vector<Coin> sortedCoins = coins;
   for(int i = 0;i<sortedCoins.size();i++)
   {
      for(int j = 0; j<sortedCoins.size();j++)
      {

         if(sortedCoins[i].m > sortedCoins[j].m)
         {
            temp = sortedCoins[i].m;
            sortedCoins[i].m = sortedCoins[j].m;
            sortedCoins[j].m = temp;

            temp1 = sortedCoins[i].c;
            sortedCoins[i].c = sortedCoins[j].c;
            sortedCoins[j].c = temp1;

         }
      }
    }


    //навсякий
    res.clear();

    std::vector<int> A(sortedCoins.size(), 0);
    for (int i = 0; i < sortedCoins.size(); ++i) 
    {
      int r= C / sortedCoins[i].m;
      
      if(sortedCoins[i].c < r)
      {
        A[i] = sortedCoins[i].c;
        C = C - sortedCoins[i].m*sortedCoins[i].c;
      }
     
      if(sortedCoins[i].c >= r)
      {
      A[i] = r;
      C = C % sortedCoins[i].m;
      }
    }
    
    if(C > 0)
       return false;
    
    for (int i = 0; i < sortedCoins.size(); ++i) {
        for (int j = 0; j < A[i]; ++j)
            res.push_back(sortedCoins[i].m);
    }

    return true; 
}