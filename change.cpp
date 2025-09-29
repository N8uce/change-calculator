#include "change.hpp"
#include <vector>

const int INF = 1e9; 

bool changeM(int C, const std::vector<Coin>& coins, std::vector<int>& res) 
{
    int C1 = C;
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

    if (C == 0) 
    {
    for (int i = 0; i < sortedCoins.size(); ++i) {
        for (int j = 0; j < A[i]; ++j)
            res.push_back(sortedCoins[i].m);
    }
    return true;
    }
   

    if(C > 0)
    {
       for(int i =0 ; i < A.size(); i++)
            A[i] = 0;

      std::vector<int> F(C1+1,INF);
      F[0] = 0;


   //динамическое решение, чтобы точно найти комбинацию
   for (int i = 0; i < sortedCoins.size(); i++) 
   {
    int coin = sortedCoins[i].m;
    int count = sortedCoins[i].c;
    for (int k = 1; k <= count; k++) { 
        for (int S = C1; S >= coin; S--) {
            if (F[S - coin] + 1 < F[S])
                F[S] = F[S - coin] + 1;
        }
    }
   }


      int S = C1;
      //получаем ответ или не получаем
      if(F[C1] != INF)
      {
       while(S != 0)
       {
          for (int i = 0; i < sortedCoins.size();i++)
          {
            
             if (S - sortedCoins[i].m >= 0 && (F[S] == (F[S - sortedCoins[i].m] + 1)) && A[i] < sortedCoins[i].c)
             {
                A[i] +=1;
                S -= sortedCoins[i].m;
                break;
             }
            }
       }
    }

     if (S == 0)
      {
     for (int i = 0; i < sortedCoins.size(); ++i) {
         for (int j = 0; j < A[i]; ++j)
        res.push_back(sortedCoins[i].m);
         }

       return true;
      }
       
      if (S > 0)
      return false;
      
    }
return false;
}