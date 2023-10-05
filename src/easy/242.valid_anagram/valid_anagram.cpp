#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

// problem link : https://leetcode.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        // ! easy approach but there should be a better way
        // std::sort(s.begin(),s.end());
        // std::sort(t.begin(),t.end());
        // return s == t;
        if (s.size() != t.size())
            return false;

        std::unordered_map<char,int> fraq_s;
        std::unordered_map<char,int> fraq_t;
        int num_value_s = 0;
        int num_value_t = 0;
        int size = s.size();
        for (int i = 0 ; i < size; i++)
        {
            num_value_s += s[i] - '0';
            num_value_t += t[i] - '0';
            // fraq_s[s[i]]++;
            // fraq_t[t[i]]++;
        }
        std::cout << num_value_s << "   " << num_value_t  << std::endl;
        return num_value_s == num_value_t;
    }
};

int main(){
    Solution sol;
    std::cout << sol.isAnagram("cat","tac") << std::endl;
}