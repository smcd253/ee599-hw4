#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>     // std::vector<int>
#include <algorithm>  // std::copy_if(), std::transform()
#include <math.h>     // std::pow()
#include <numeric>    // std::accumulate()

class Solution {
public:
  /**
   * Filters out the odd numbers and keeps the even numbers in a
   * vector (use std::copy_if) and returns a new vector that contains the results.
   * */
  std::vector<int> filter_odds(std::vector<int> in);

  /**
   * Takes a vector of integers as input in and outputs a new vector
   * out where out[i] = in[i] ^ 2 (Use std::transform).
   * */
  std::vector<int> map_square(std::vector<int> in);

  /**
   * Sums up all elements in a vector (Use std::accumulate)
   * */
  int reduce(std::vector<int> in);
};

#endif