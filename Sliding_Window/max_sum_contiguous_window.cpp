using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    int running_sum = 0;
    // TODO: Write your code here
    int windowStart = 0;
    int windowEnd = 0;
    for (windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
        running_sum += arr[windowEnd];

        if (windowEnd >= (k - 1)) {
            maxSum = max(maxSum, running_sum);
            running_sum -= arr[windowStart];
            windowStart++;
        }
    }
    return maxSum;
  }
};