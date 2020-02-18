#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

/******************** Solution::heap_sort() ********************/
TEST(HEAP_SORT, STANDARD) {
  Solution solution;
  std::vector<int> input = {6, 2, 1, 4, 5, 3};
  solution.heap_sort(input);
  std::vector<int> expected = {1, 2, 3, 4, 5, 6};
  EXPECT_EQ(expected, input);
}

TEST(HEAP_SORT, EMPTY) {
  Solution solution;
  std::vector<int> input = {};
  solution.heap_sort(input);
  std::vector<int> expected = {};
  EXPECT_EQ(expected, input);
}

TEST(HEAP_SORT, SINGULAR) {
  Solution solution;
  std::vector<int> input = {1};
  solution.heap_sort(input);
  std::vector<int> expected = {1};
  EXPECT_EQ(expected, input);
}

TEST(HEAP_SORT, NEGATIVES) {
  Solution solution;
  std::vector<int> input = {-1, -2, -3};
  solution.heap_sort(input);
  std::vector<int> expected = {-3, -2, -1};
  EXPECT_EQ(expected, input);
}