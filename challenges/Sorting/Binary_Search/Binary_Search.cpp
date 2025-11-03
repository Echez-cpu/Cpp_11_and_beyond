#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        // Use brute-force for very small arrays
        if (n <= 10) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == target) return i;
            }
            return -1;
        }

        // Use binary search for larger arrays
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1; // Not found
    }
};
