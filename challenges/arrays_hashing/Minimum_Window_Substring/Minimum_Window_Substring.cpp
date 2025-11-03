#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";

        unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }

        int have = 0;
        int needCount = need.size();
        unordered_map<char, int> window;

        int left = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            while (have == needCount) {
                // Update smallest window
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";
        else
            return s.substr(minStart, minLen);
    }
};
