#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            int area = h * w;

            maxWater = max(maxWater, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};



/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int area = 0;
        while(l <= r) {
            int calculatedArea = min(height[l], height[r]) * (r - l);
            area = max(area, calculatedArea);

            if(height[l] < height[r]) l++;
            else r--;
        }

        return area;
    }
};*/
