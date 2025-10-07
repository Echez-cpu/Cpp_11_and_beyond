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





