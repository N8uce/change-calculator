#include <gtest/gtest.h>
#include <vector>
#include "change.hpp"

TEST(ChangeTest, ExactChangePossible) {
    std::vector<int> coins = {100, 50, 10, 5, 2, 1};
    std::vector<int> res;

    bool result = changeM(186, coins, res);
    EXPECT_TRUE(result);

    int sum = 0;
    for (int c : res) sum += c;
    EXPECT_EQ(sum, 186);

    std::vector<int> expected = {100, 50, 10, 10, 10, 5, 1};
    EXPECT_EQ(res, expected);
}

TEST(ChangeTest, ChangeNotPossible) {
    std::vector<int> coins = {5, 3};
    std::vector<int> res;

    bool result = changeM(2, coins, res);
    EXPECT_FALSE(result);
    EXPECT_TRUE(res.empty());
}

TEST(ChangeTest, UseAllCoins) {
    std::vector<int> coins = {5, 3, 1};
    std::vector<int> res;

    bool result = changeM(9, coins, res);
    EXPECT_TRUE(result);

    std::vector<int> expected = {5, 3, 1}; 
    EXPECT_EQ(res, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
