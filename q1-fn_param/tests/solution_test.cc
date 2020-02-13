#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

/******************** Solution::filter_odds() ********************/
TEST(FILTER_ODDS_TEST, STANDARD) {
  Solution solution;
  std::vector<int> input = {1, 2, 3, 4, 5, 6};
  std::vector<int> actual = solution.filter_odds(input);
  std::vector<int> expected = {2, 4, 6};
  EXPECT_EQ(expected, actual);
}

TEST(FILTER_ODDS_TEST, EMPTY) {
  Solution solution;
  std::vector<int> input = {};
  std::vector<int> actual = solution.filter_odds(input);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(FILTER_ODDS_TEST, SINGLETON_ZERO) {
  Solution solution;
  std::vector<int> input = {0};
  std::vector<int> actual = solution.filter_odds(input);
  std::vector<int> expected = {0};
  EXPECT_EQ(expected, actual);
}

TEST(FILTER_ODDS_TEST, NEGATIVES) {
  Solution solution;
  std::vector<int> input = {-1, -2, -3, -4, -5, -6};
  std::vector<int> actual = solution.filter_odds(input);
  std::vector<int> expected = {-2, -4, -6};
  EXPECT_EQ(expected, actual);
}

/******************** Solution::map_square() ********************/
TEST(MAP_SQUARE_TEST, STANDARD) {
  Solution solution;
  std::vector<int> input = {1, 2, 3, 4, 5, 6};
  std::vector<int> actual = solution.map_square(input);
  std::vector<int> expected = {1, 4, 9, 16, 25, 36};
  EXPECT_EQ(expected, actual);
}

TEST(MAP_SQUARE_TEST, EMPTY) {
  Solution solution;
  std::vector<int> input = {};
  std::vector<int> actual = solution.map_square(input);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, actual);
}

TEST(MAP_SQUARE_TEST, SINGLETON_ZERO) {
  Solution solution;
  std::vector<int> input = {0};
  std::vector<int> actual = solution.map_square(input);
  std::vector<int> expected = {0};
  EXPECT_EQ(expected, actual);
}

TEST(MAP_SQUARE_TEST, NEGATIVES) {
  Solution solution;
  std::vector<int> input = {-1, -2, -3, -4, -5, -6};
  std::vector<int> actual = solution.map_square(input);
  std::vector<int> expected = {1, 4, 9, 16, 25, 36};
  EXPECT_EQ(expected, actual);
}

/******************** Solution::reduce() ********************/
TEST(REDUCE_TEST, STANDARD) {
  Solution solution;
  std::vector<int> input = {1, 2, 3, 4, 5, 6};
  int actual = solution.reduce(input);
  int expected = 21;
  EXPECT_EQ(expected, actual);
}

TEST(REDUCE_TEST, EMPTY) {
  Solution solution;
  std::vector<int> input = {};
  int actual = solution.reduce(input);
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(REDUCE_TEST, SINGLETON_ZERO) {
  Solution solution;
  std::vector<int> input = {0};
  int actual = solution.reduce(input);
  int expected = 0;
  EXPECT_EQ(expected, actual);
}

TEST(REDUCE_TEST, NEGATIVES) {
  Solution solution;
  std::vector<int> input = {-1, -2, -3, -4, -5, -6};
  int actual = solution.reduce(input);
  int expected = -21;
  EXPECT_EQ(expected, actual);
}