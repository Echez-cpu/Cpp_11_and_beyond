// Better time complexity

#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (size_t i = 0; i < nums.size(); ++i) {
        int current = nums[i];     
        if (seen.count(current) > 0) 
            return true;
        seen.insert(current);         
    }

    return false;                     
}




// Another solution but timea out with a very large set of numbers... Write a main

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {

//         auto it = nums.begin();

//         // auto dup = nums.begin() + 1;


//         while(it != nums.end())
//         {
//             auto dup = it + 1;
//             while(dup != nums.end())
//             {
//                 if(*it == *dup)
//                 {
//                     return true;
//                 }
//                 dup++;
//             }
//             it++;
//         }
        
//         return false;
//     }
// };







