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

// nums = [4, 7, 1, 3, 7]

// Hash-based approach (unordered_set)
// seen = {}

// Step 1: 4 → not in set → add → seen = {4}
// Step 2: 7 → not in set → add → seen = {4, 7}
// Step 3: 1 → not in set → add → seen = {1, 4, 7}
// Step 4: 3 → not in set → add → seen = {1, 3, 4, 7}
// Step 5: 7 → already in set → return true

// (1) Each lookup or insert is O(1) on average (thanks to hash table).

// (2) Total operations = roughly n → O(n)

// Fast even for huge arrays.






// Another solution but timea out with a very large set of numbers... Write a main

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        auto it = nums.begin();

        // auto dup = nums.begin() + 1;


        while(it != nums.end())
        {
            auto dup = it + 1;
            while(dup != nums.end())
            {
                if(*it == *dup)
                {
                    return true;
                }
                dup++;
            }
            it++;
        }
        
        return false;
    }
};


// Brute-force (nested loops)

// i = 0: check 4 against 7, 1, 3, 7 → 4 comparisons
// i = 1: check 7 against 1, 3, 7 → 3 comparisons
// i = 2: check 1 against 3, 7 → 2 comparisons
// i = 3: check 3 against 7 → 1 comparison
// i = 4: nothing left


// Total comparisons = 4 + 3 + 2 + 1 = 10 → O(n²)

// Works fine for small arrays. ❌ Too slow for large arrays (n=100,000 → ~5,000,000,000 comparisons).




