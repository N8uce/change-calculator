#include <gtest/gtest.h>
#include <vector>
#include "change.hpp"

// 1
TEST(ChangeTest, ExactChangePossible) {
    std::vector<Coin> coins = {{100,1}, {50,1}, {10,3}, {5,1}, {2,1}, {1,1}};
    std::vector<int> res;

    bool result = changeM(186, coins, res);
    EXPECT_TRUE(result);

    int sum = 0;
    for (int c : res) sum += c;
    EXPECT_EQ(sum, 186);

    std::vector<int> expected = {100, 50, 10, 10, 10, 5, 1};
    EXPECT_EQ(res, expected);
}

// 2
TEST(ChangeTest, ChangeNotPossible) {
    std::vector<Coin> coins = {{5,1}, {3,1}};
    std::vector<int> res;

    bool result = changeM(6, coins, res);
    EXPECT_FALSE(result);
    EXPECT_TRUE(res.empty());
}

// 3
TEST(ChangeTest, UseAllCoins) {
    std::vector<Coin> coins = {{5,1}, {3,1}, {1,1}};
    std::vector<int> res;

    bool result = changeM(9, coins, res);
    EXPECT_TRUE(result);

    std::vector<int> expected = {5, 3, 1};
    EXPECT_EQ(res, expected);
}

// 4
TEST(ChangeTest, ZeroChange) {
    std::vector<Coin> coins = {{1,5}, {2,3}, {5,2}};
    std::vector<int> res;

    bool result = changeM(0, coins, res);
    EXPECT_TRUE(result);
    EXPECT_TRUE(res.empty());
}

// 5
TEST(ChangeTest, UnsortedCoins) {
    std::vector<Coin> coins = {{2,2}, {10,1}, {1,3}, {50,1}};
    std::vector<int> res;

    bool result = changeM(12, coins, res);
    EXPECT_TRUE(result);
    EXPECT_EQ(res, std::vector<int>({10, 2}));
}

// 6
TEST(ChangeTest, NotEnoughCoins) {
    std::vector<Coin> coins = {{5, 1}, {2, 1}}; 
    std::vector<int> res;

    bool result = changeM(10, coins, res);
    EXPECT_FALSE(result);
    EXPECT_TRUE(res.empty());
}

// 7
TEST(ChangeTest, MultipleSameCoin) {
    std::vector<Coin> coins = {{5, 3}, {2, 1}, {1, 1}};
    std::vector<int> res;

    bool result = changeM(15, coins, res);
    EXPECT_TRUE(result);
    std::vector<int> expected = {5, 5, 5};
    EXPECT_EQ(res, expected);
}

// 8
TEST(ChangeTest, NoCoins) {
    std::vector<Coin> coins = {};
    std::vector<int> res;

    bool result = changeM(10, coins, res);
    EXPECT_FALSE(result);
    EXPECT_TRUE(res.empty());
}

// 9
TEST(ChangeTest, GreedyAlgorithmFailsToFormTarget) {
    std::vector<Coin> coins = {{5, 2}, {2, 4}}; 
    std::vector<int> res;

    bool result = changeM(8, coins, res);
    EXPECT_TRUE(result);

    std::vector<int> expected = {2, 2, 2, 2};
    EXPECT_EQ(res, expected);
}

// 10
TEST(ChangeTest, ManyOperationsStressTest) {
    std::vector<Coin> coins = {
        {100, 50}, {50, 100}, {20, 200}, {10, 500}, {5, 1000}, {2, 2000}, {1, 5000}
    };

    for (int target = 0; target <= 5000; target += 37) {  
        std::vector<int> res;
        bool result = changeM(target, coins, res);

        if (result) {
            int sum = 0;
            for (int c : res) sum += c;
            EXPECT_EQ(sum, target);
        } else {
            EXPECT_TRUE(res.empty());
        }
    }
}

// 11
TEST(ChangeTest, NegativeTarget) {
    std::vector<Coin> coins = {{1,5}, {2,3}, {5,2}};
    std::vector<int> res;

    bool result = changeM(-10, coins, res);

    EXPECT_FALSE(result);
    
    EXPECT_TRUE(res.empty());
}

// 12
TEST(ChangeTest, OnlyOneNominalMultipleCoins) {
    std::vector<Coin> coins = {{5, 4}};
    std::vector<int> res;

    bool result = changeM(15, coins, res);
    EXPECT_TRUE(result);

    std::vector<int> expected = {5, 5, 5};
    EXPECT_EQ(res, expected);
}

// 13
TEST(ChangeTest, CoinWithZeroCount) {
    std::vector<Coin> coins = {{5, 0}, {2, 3}, {1, 5}}; 
    std::vector<int> res;

    bool result = changeM(7, coins, res);
    EXPECT_TRUE(result);

    std::vector<int> expected = {2, 2, 2, 1}; 
    EXPECT_EQ(res, expected);
}

// 14
TEST(ChangeTest, DuplicateDenominations) {
    std::vector<Coin> coins = {{5,1}, {5,1}, {2,3}};
    std::vector<int> res;
    bool result = changeM(10, coins, res);
    EXPECT_TRUE(result);
    std::vector<int> expected = {5, 5}; 
    EXPECT_EQ(res, expected);
}

// 15
TEST(ChangeTest, ZeroValueCoinShouldNotHelp) {
    std::vector<Coin> coins = {{0, 5}, {2, 1}};
    std::vector<int> res;

    bool result = changeM(4, coins, res);

    EXPECT_FALSE(result);
    EXPECT_TRUE(res.empty());
}
// 16
TEST(ChangeTest, NegativeCoinValue) {
    std::vector<Coin> coins = {{-5, 2}, {2, 2}};
    std::vector<int> res;

    bool result = changeM(4, coins, res);

    EXPECT_TRUE(result);
    EXPECT_EQ(res, std::vector<int>({2,2}));
}

// 17
TEST(ChangeTest, NegativeCoinCounts) {
    std::vector<Coin> coins = {{5, -20}, {2, 2}};
    std::vector<int> res;

    bool result = changeM(4, coins, res);

    EXPECT_TRUE(result);
    EXPECT_EQ(res, std::vector<int>({2,2}));
}
// 18  
TEST(ChangeTest, VeryLargeAmount) {
    std::vector<Coin> coins = {{1, 1'000'000}};
    std::vector<int> res;

    bool result = changeM(1'000'000'000, coins, res);

    EXPECT_FALSE(result);
}
// 19
TEST(ChangeTest, LargeAmountWithSolution) {
    std::vector<Coin> coins = {
        {1000000, 1000}, 
        {1000, 1000},     
        {1, 1000}         
    };

    std::vector<int> res;
    int amount = 1'234'567;

    bool result = changeM(amount, coins, res);
    EXPECT_TRUE(result);
    int sum = 0;
    for (int c : res) sum += c;
    EXPECT_EQ(sum, amount);
}

// 20
TEST(ChangeTest, ExtremeCoinValue) {
    std::vector<Coin> coins = {{INT_MAX, 1}, {1, 5}};
    std::vector<int> res;

    bool result = changeM(5, coins, res);

    EXPECT_TRUE(result);
    EXPECT_EQ(res, std::vector<int>({1,1,1,1,1}));
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
