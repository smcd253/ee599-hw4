#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>     // std::vector<int>
#include <queue>
#ifdef __linux__ 
    #include <climits>      // INT_MAX (linux)

#elif __APPLE__
    #include <limits>       // INT_MAX (darwin)
#endif

class Solution {
public:
  /**
   * Find the k(th) largest element in an unsorted vector and return that value.
   * */
  int kth_largest(std::vector<int>& input, int k);

};

#endif