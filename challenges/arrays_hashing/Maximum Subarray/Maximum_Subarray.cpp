#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            currentSum = max(nums[i], currentSum + nums[i]);
            
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};



// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int currentSum = nums[0];
//         int maxSum = nums[0];

//         for (size_t i = 1; i < nums.size(); ++i) {
//             if (currentSum + nums[i] > nums[i])
//                 currentSum = currentSum + nums[i];
//             else
//               currentSum = nums[i];

//             if (currentSum > maxSum)
//               maxSum = currentSum;
//         }

//         return maxSum;
//     }
// };






// using namespace std;

// int maxSubArray(vector<int>& nums) {
//     int currentSum = nums[0];
//     int maxSum = nums[0];

//     // Track indices
//     int start = 0;         // where the current subarray starts
//     int bestStart = 0;     // start of best subarray
//     int bestEnd = 0;       // end of best subarray

//     for (size_t i = 1; i < nums.size(); ++i) {

//         // If starting fresh gives a better sum, restart
//         if (nums[i] > currentSum + nums[i]) {
//             currentSum = nums[i];
//             start = i;  // new subarray starts here
//         } else {
//             currentSum = currentSum + nums[i]; // continue current subarray
//         }

//         // Update global max and record indices
//         if (currentSum > maxSum) {
//             maxSum = currentSum;
//             bestStart = start;
//             bestEnd = i;
//         }
//     }

//     // Print the subarray
//     cout << "Best subarray: [ ";
//     for (int j = bestStart; j <= bestEnd; ++j)
//         cout << nums[j] << " ";
//     cout << "]" << endl;

//     return maxSum;
// }

// int main() {
//     vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

//     int result = maxSubArray(nums);
//     cout << "Maximum subarray sum: " << result << endl;

//     return 0;
// }



