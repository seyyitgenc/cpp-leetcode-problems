#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

// problem link : https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    // ! brute force approach. NOT GOOD
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<char> set;
        int max = 0;
        if(s == "")return 0;
        for (int i = 0; i < s.size(); i++)
        {
            int count =  0;
            for (int j = i; j < s.size(); j++)
            {
                if(set.count(s[j]) < 1){
                    set.insert(s[j]);
                    count++;
                    if (count >= max)
                        max = count;
                }
                else{
                    count = 0;
                    set.clear();
                    break;
                }
            }
        }
        return max;
    }
};

int main(){
    Solution sol;
    std::string s = {"aab"};
    std::cout << sol.lengthOfLongestSubstring(s);
}