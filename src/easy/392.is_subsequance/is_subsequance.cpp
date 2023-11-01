#include <iostream>
#include <string>

// problem link : https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int p1 = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[p1] == t[i])
                p1++;
        }
        return p1 == s.size();
    }
};

int main(){
    Solution s1;
    
    std::string s = "", t = "ahgbdc";
    std::cout << s1.isSubsequence(s,t); 
    return 0;
}

