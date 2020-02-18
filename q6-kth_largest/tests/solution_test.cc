#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

/******************** Solution::kth_largest() ********************/
TEST(KTH_LARGEST, STANDARD) {
  Solution solution;
  std::vector<int> input = {6, 2, 1, 4, 5, 3};
  int actual = solution.kth_largest(input, 1);
  int expected = 6;
  EXPECT_EQ(expected, actual);
}

TEST(KTH_LARGEST, EMPTY) {
  Solution solution;
  std::vector<int> input = {};
  int actual = solution.kth_largest(input, 1);
  int expected = INT_MIN;
  EXPECT_EQ(expected, actual);
}

TEST(KTH_LARGEST, INVALID_K) {
  Solution solution;
  std::vector<int> input = {1, 2, 3};
  int actual = solution.kth_largest(input, 0);
  int expected = INT_MIN;
  EXPECT_EQ(expected, actual);
}

TEST(KTH_LARGEST, K_TOO_LARGE) {
  Solution solution;
  std::vector<int> input = {1, 2, 3};
  int actual = solution.kth_largest(input, 3);
  int expected = INT_MIN;
  EXPECT_EQ(expected, actual);
}
