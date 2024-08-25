/**
 * @file no_brain_sort.cpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief No brain sort - practical sorting algorithm
 * @version 0.2
 * @date 24-08-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# include <bits/stdc++.h>
# include "no_brain_sort.hpp"
using namespace std;


void NoBrainSort::sort(vector<int>::iterator front, vector<int>::iterator end)
{
  vector<int>::iterator offset = front + isolateNegatives(front, end);
  {
  int mask = minMask(offset, end);
  arrange(offset, end, mask, 0);
  }
  {
  int mask = minMask(front, offset);
  arrange(front, offset, mask, 1);   
  }
  restoreNegatives(front, offset);
}


int NoBrainSort::minMask(vector<int>::iterator front, vector<int>::iterator end)
{
  // Retrieve the maximum of the vector
  int maximum = 0;
  for (auto iter = front; iter != end; ++ iter)
  {
    if (*iter > maximum)
    {
      maximum = *iter;
    }
  }
  // Read the bits of maximum to construct the minimum mask
  int mask = 1;
  maximum >>= 1;
  while (maximum)
  {
    maximum >>= 1;
    mask <<= 1;
  }
  return mask;
}


void NoBrainSort::arrange(vector<int>::iterator front, vector<int>::iterator end, int mask, bool reverse)
{
  if (front == end or not mask)
  {
    return;
  }
  vector<int>::iterator bound = front;
  int tmp;
  for (auto iter = front; iter != end; ++ iter)
  {
    if (reverse ? (*iter & mask) : not (*iter & mask))
    {
      tmp = *iter;
      *iter = *bound;
      *bound = tmp;
      ++ bound;
    }
  }

  mask >>= 1;
  arrange(front, bound, mask, reverse);
  arrange(bound, end, mask, reverse);
}


int NoBrainSort::isolateNegatives(vector<int>::iterator front, vector<int>::iterator end)
{
  vector<int>::iterator bound = front;
  int tmp;
  for (auto iter = front; iter < end; ++ iter)
  {
    if (*iter < 0)
    {
      tmp = -(*iter);
      *iter = *bound;
      *bound = tmp;
      ++ bound;
    }
  }
  return bound - front;
}


void NoBrainSort::restoreNegatives(vector<int>::iterator front, vector<int>::iterator end)
{
  for (auto iter = front; iter != end; ++ iter)
  {
    *iter = -(*iter);
  }
}


/**
 * @brief Run a few tests to ensure that the NBS algorithm is correct
 * 
 * @return int 
 */
int main()
{
  vector<vector<int>> testNums {
    {1, 5, 10, 15, 20, 25},
    {8, 1, 5, 9, 13, 2, 0},
    {-5, -1, 5, 1, 1, 3},
    {0, 0, 0, -1, -5, -3},
    {100000, -1000000, 1, 2, -7}
  };
  size_t size;

  for (auto iter = testNums.begin(); iter != testNums.end(); ++ iter)
  {
    size = iter->size();
    cout << "[";
    for (size_t index = 0; index < size; ++ index) {
      cout << iter->at(index) << (index != size - 1 ? ", " : "]");
    }
    cout << " -> [";
    NoBrainSort::sort(iter->begin(), iter->end());
    for (size_t index = 0; index < size; ++ index) {
      cout << iter->at(index) << (index != size - 1 ? ", " : "]");
    }
    cout << endl;
  }

  return 0;
}