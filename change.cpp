#include "change.hpp"
#include <vector>
#include <algorithm>
constexpr int INF = 1'000'000'000;

bool changeM(int amount, const std::vector<Coin>& coins, std::vector<int>& res) 
{
   //очищаем res, если вдруг будет 
   //повторное использование функции
   res.clear();
   //для случая если изначально сдача равна 0
   if (amount == 0) 
   return true;

   //сортировка монет
   std::vector<Coin> sortedCoins = coins;
   std::sort(sortedCoins.begin(), sortedCoins.end(),
          [](const Coin& a, const Coin& b) {
              return a.m > b.m; //по убыванию номинала
          });
   //массив для записи в него ответа
   std::vector<int> A(sortedCoins.size(), 0);
   std::vector<int> F(amount+1,INF);//DP массив
   F[0] = 0;//начальное значение

   //динамическое решение(DP), чтобы точно найти комбинацию
   for (int i = 0; i < sortedCoins.size(); i++) 
   {
    int coin = sortedCoins[i].m;//монетка
    int count = sortedCoins[i].c;//её количество
      for (int k = 1; k <= count; k++) { 
         for (int S = amount; S >= coin; S--) {
               if (F[S - coin] + 1 < F[S])
                F[S] = F[S - coin] + 1;
             }
         }
   }

   //если невозможно выдать сдачу
   if (F[amount] == INF)
      return false;
   //если решение есть, ответ восстанавливается
   while(amount != 0)
   {
      for (int i = 0; i < sortedCoins.size();i++)
      {
      if (amount - sortedCoins[i].m >= 0 && 
         (F[amount] == (F[amount - sortedCoins[i].m] + 1)) && 
         A[i] < sortedCoins[i].c)
         {
            A[i] +=1;
            amount -= sortedCoins[i].m;
            break;
         }
      }
   }
   //ответик
    for (size_t i = 0; i < sortedCoins.size(); ++i) {
        for (int j = 0; j < A[i]; ++j)
            res.push_back(sortedCoins[i].m);
    }
return true;
}