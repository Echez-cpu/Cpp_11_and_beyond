#include <map>
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            auto fixed = it + 1;
            while (fixed != nums.end()) {
                if (*it + *fixed == target) {
                    // return indices, not values
                    return {static_cast<int>(it - nums.begin()),
                            static_cast<int>(fixed - nums.begin())};
                }
                ++fixed;
            }
        }
        return {};
    }
};



int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target); 

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}




// Another way

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    auto result = s.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

