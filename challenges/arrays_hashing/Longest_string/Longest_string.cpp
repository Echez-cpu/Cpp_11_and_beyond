int lengthOfLongestSubstring(string s) {
    std::string hold;
    int highest_count = 0;

    for (int i = 0; i < s.size(); i++) {
        size_t dupIndex = hold.find(s[i]);

        if (dupIndex != std::string::npos) {
            if (hold.length() > highest_count)
                highest_count = hold.length();

            hold = hold.substr(dupIndex + 1);
        }

        hold += s[i];
    }

    // Final check for last substring
    if (hold.length() > highest_count)
        highest_count = hold.length();

    return highest_count;
}






// Best time

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); ++right) {
            char current = s[right];

            // If current char was seen and is inside current window
            if (lastSeen.find(current) != lastSeen.end() && lastSeen[current] >= left) {
                // Move left pointer to one after the last occurrence
                left = lastSeen[current] + 1;
            }

            // Update last seen position
            lastSeen[current] = right;

            // Calculate current window size
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
