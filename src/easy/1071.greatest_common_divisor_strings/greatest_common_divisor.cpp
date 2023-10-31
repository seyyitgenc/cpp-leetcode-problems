#include <string>
#include <iostream>

// problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2) {
        int len1 = str1.size(), len2 = str2.size();
        int min_iter = std::min(len1, len2);
        int max_iter = std::max(len1, len2);
        int divisor = 0;
        int gcd = 1;
        std::string substr = "";
        while (divisor < min_iter)
        {
            // early rejection if 2 string is not equal
            if (str1[divisor] != str2 [divisor])
                return "";
            divisor++;
            if(len1 % divisor == 0 && len2 % divisor == 0)
            {
                gcd = divisor;
                substr = str1.substr(0, gcd);
            }
        }
        return (str1 + str2 == str2 + str1 ? substr : "");
    }
};

int main(){
    Solution s1;
    std::string str1 = "TAUXXTAUXXTAUXXTAUXXTAUXX";
    std::string str2 = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX";
    std::cout << s1.gcdOfStrings(str1, str2) << std::endl;
    return 0;
}