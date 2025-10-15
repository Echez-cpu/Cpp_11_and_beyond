#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (size_t i = 1; i < intervals.size(); ++i) {
      
        vector<int>& last = merged.back();

        if (intervals[i][0] <= last[1]) {
            last[1] = max(last[1], intervals[i][1]);
        } else {
          
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}

// int main() {
//     vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
//     vector<vector<int>> result = merge(intervals);

//     cout << "[ ";
//     for (auto& interval : result) {
//         cout << "[" << interval[0] << "," << interval[1] << "] ";
//     }
//     cout << "]" << endl;

//     return 0;
// }
