#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// problem link : https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = "";
        std::sort(strs.begin(),strs.end());

        std::string first = strs[0];
        std::string last = strs[strs.size() - 1];

        int j = 0;
        for (int i = 0; i < min(first,last).size(); i++)
        {
            if (first[i] != last[i])
                return prefix;
            prefix += first[i];
        }
        

        return prefix;   
    }
};

int main(){
    Solution sol;
    std::vector<std::string> input = {"flower","flow","flight"};
    std::cout << sol.longestCommonPrefix(input);
    return 0;
}