#include <cctype>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); });

        std::string second;

       int len = s.size();
       int i = 0;
       while(i < len)
       {
         char a = s[i];
         if (isalnum(static_cast<unsigned char>(a))) 
         {
            second += a;
         }
         i++;
       }

       std::string reversed = second;

       std::reverse(reversed.begin(), reversed.end());

       int result = reversed.compare(second);

        if (result == 0) 
        {
            return true;
        }

        else
        {
            return false;
        }
        
    }
};




// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0;
//         int right = s.size() - 1;

//         while (left < right) {
//             while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
//                 left++;
//             }

//             while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
//                 right--;
//             }

//             if (tolower(static_cast<unsigned char>(s[left])) !=
//                 tolower(static_cast<unsigned char>(s[right]))) {
//                 return false;
//             }

//             left++;
//             right--;
//         }

//         return true;
//     }
// };



