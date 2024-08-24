/**
 * @file no_brain_sort.hpp
 * @author JakeTheRealOne (jakelevrai@outlook.be)
 * @brief No brain sort - practical sorting algorithm
 * @version 0.2
 * @date 24-08-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


# pragma once


# include <bits/stdc++.h>
using namespace std;


// STEPS:
// 1: Separate positive and negative integers
// For positive & negative numbers (separated):
// 2: Get the minimum number of bits to represents the integers
// For each bit of each integer (i):
// 3: Split into 2 sublists depending on INT[i] == 0 or 1

// TIME COMPLEXITY:
// Best scenario: O(n)
// Worst scenario: O(n)

// MEMORY COMPLEXITY:
// O(1)


namespace NoBrainSort
{
  /**
   * @brief Main function, sort in place a vector of integers
   * 
   * @param front The first element of the vector
   * @param end The end of the vector
   */
  void sort(vector<int>::iterator front, vector<int>::iterator end);

  /**
   * @brief Arrange the integers of the vector using the minimum mask of this vector
   * @pre The integers in the vector has to be positives 
   * 
   * @param front The first element of the vector
   * @param end The end of the vector
   * @param mask The minimum mask of the vector
   * @param reverse The reverse flag (0 -> ascending ored, 1 -> descending order)
   */
  void arrange(vector<int>::iterator front, vector<int>::iterator end, int mask, bool reverse = 0);

  /**
   * @brief Get the minimum mask that can be used for every integer of
   * the vector
   * @pre The integers in the vector has to be positives 
   *
   * @param front The first element of the vector
   * @param end The end of the vector
   * @return int The minimum mask
   */
  int minMask(vector<int>::iterator front, vector<int>::iterator end);

  /**
   * @brief Isolate the negative integers of the vector at the begin of
   * the vector
   * 
   * @param front The first element of the vector
   * @param end The end of the vector
   * @param reverse The reverse flag (0 -> ascending ored, 1 -> descending order)
   * @return int The number of negative integers
   */
  int isolateNegatives(vector<int>::iterator front, vector<int>::iterator end);

  /**
   * @brief Restore a vector of negative integers (arrangement)
   * 
   * @param front The first element of the vector
   * @param end The end of the vector
   * @param reverse The reverse flag (0 -> ascending ored, 1 -> descending order)
   */
  void restoreNegatives(vector<int>::iterator front, vector<int>::iterator end);
}
