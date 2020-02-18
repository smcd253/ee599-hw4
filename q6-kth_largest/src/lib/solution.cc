#include "solution.h"

// Runtime = &theta;(n*k), where k &isin; [1, n] --> O(n^2)
int Solution::kth_largest(const std::vector<int>& input, int k)
{
  int max = INT_MIN;

  if((int)input.size() > 0 && k > 0 && k < (int)input.size())
  {
    std::vector<int> input_copy(input.begin(), input.end());
    std::vector<int>::iterator it;
    
    int j = 0;
    while(j < k)
    {
      int j_max = INT_MIN;
      std::vector<int>::iterator temp;
      for(it = input_copy.begin(); it != input_copy.end(); it++)
      {
        if(*it > j_max)
        {
          j_max = *it;
          temp = it;
        }
      }

      input_copy.erase(temp);
      j++;
      max = j_max;
    }
  }
  
  return max;
}
