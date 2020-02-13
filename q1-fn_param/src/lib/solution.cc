#include "solution.h"

// helper functions to pass as parameters
bool is_even(int i){ return ((i % 2) == 0); }
int square(int i){ return std::pow(i, 2); }

// Runtime = &theta;(2 + n + n + 1) --> O(n)
std::vector<int> Solution::filter_odds(std::vector<int> in)
{
  std::vector<int> out(in.size());

  // input validation
  if (!in.empty())
  {
    // copy all even values from in to output vector
    std::vector<int>::iterator it = std::copy_if(in.begin(), in.end(), out.begin(), is_even);
    
    // resize output vector to only contain populated values
    out.resize(std::distance(out.begin(), it));
  }
 
  return out;
}

// Runtime = &theta;(2 + n + n + 1) --> O(n)
std::vector<int> Solution::map_square(std::vector<int> in)
{
  std::vector<int> out(in.size());

  // input validation
  if (!in.empty())
  {
    // Square all values in input vector and place in output vector
    std::vector<int>::iterator it = std::transform(in.begin(), in.end(), out.begin(), square);
    
    // resize output vector to only contain populated values
    out.resize(std::distance(out.begin(), it));
  }
 
  return out;
}


// Runtime = &theta;(2 + n + 1) --> O(n)
int Solution::reduce(std::vector<int> in)
{
  int result = 0;

  // input validation
  if (!in.empty())
  {
    // Square all values in input vector and place in output vector
    result = std::accumulate(in.begin(), in.end(), 0);
  }
 
  return result;
}