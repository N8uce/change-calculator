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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
