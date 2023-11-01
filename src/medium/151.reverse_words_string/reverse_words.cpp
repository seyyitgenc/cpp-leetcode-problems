#include <string>
#include <iostream>

// problem link : https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string reverse;
        int p1 = s.size() - 1, p2 = s.size() - 1;
        while(p1>= 0)
        {
            
        }
        return reverse;
    }
};

int main(){
    Solution s1;
    std::string str = "hello world  ";
    std::cout << s1.reverseWords(str); 
}