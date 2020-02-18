#include "solution.h"

// Runtime = &theta;(n*k), where k &isin; [1, n] --> O(n^2)
int Solution::kth_largest(std::vector<int>& input, int k)
{
  int max = INT_MIN;
  if((int)input.size() > 0 && k > 0 && k < (int)input.size())
  {
    std::vector<int>::iterator it;
    int j = 0;
    while(j < k)
    {
      std::vector<int>::iterator temp;
      for(it = input.begin(); it != input.end(); it++)
      {
        if(*it > max)
        {
          max = *it;
          temp = it;
        }
      }
      input.erase(temp);
      j++;
    }
  }

  return max;
}
