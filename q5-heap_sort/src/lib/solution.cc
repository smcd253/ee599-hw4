#include "solution.h"

// Runtime = &theta;(2 + n*log(n) + n + 2*n) --> O(nlog(n))
void Solution::heap_sort(std::vector<int>& input)
{
  int size = (int)input.size();
  std::priority_queue<int> sorter(input.data(), input.data() + size);
  input.clear();
  for (int i = 0; i < size; i++)
  {
    input.insert(input.begin(), sorter.top());
    sorter.pop();
  }
}