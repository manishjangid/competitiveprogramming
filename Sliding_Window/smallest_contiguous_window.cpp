/* Smallest subarray with a given sum */
/*
Problem Statement#

Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.
*/
using namespace std;

#include <iostream>
#include <limits>
#include <climits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {

    int minSize = INT_MAX;
    int running_sum = 0;
    // TODO: Write your code here
    int windowStart = 0;
    int windowEnd = 0;
    for (; windowEnd < arr.size(); windowEnd++) {
        running_sum += arr[windowEnd];
        // Move sliding window ie only windowStart to the right i.e shrink the window 
        while (running_sum >= S) {
            minSize = min(minSize, windowEnd - windowStart + 1);
            running_sum -= arr[windowStart++];
        }
    }
    return minSize == INT_MAX ? 0 : minSize;
  }
};
