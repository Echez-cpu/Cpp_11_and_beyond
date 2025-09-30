class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

       auto it = nums.begin();

       int count = 0;

       std::vector<int> ret(nums.size()); // pre-initialize vector to avoid using pushback.

       while(it != nums.end())
       {
         int temp = 1;
         auto itt = nums.begin();
            
            while(itt != nums.end())
            {
                if(it != itt)
                {
                    temp *= *itt;
                }

                itt++;
            }
            ret[count] = temp;

            count++;
            it++;
       } 
        return ret;
    }
};

// int main () {}


// Better time complexity O(n)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); 

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;   
            prefix *= nums[i];    
        }

        // Step 2: suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;  
            suffix *= nums[i];  
        }

        return answer;
    }
};
