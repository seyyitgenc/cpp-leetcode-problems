#include <string>
#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/build-an-array-with-stack-operations

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> result;
        int i = 1;
        int j = 0;
        while (i <= n && j < target.size())
        {
            if (target[j] == i){
                result.push_back("push");
                j++;
            }
            else if(target[j] != i){
                result.push_back("push");
                result.push_back("pop");
            }
                i++;
        }
            
        return result;
    }
};

int main(){
    Solution s1;
    std::vector<int> target = {1,2};
    int n = 4;
    std::vector<std::string> result = s1.buildArray(target, n);
    for (auto i : result)
        std::cout << i  << " " << std::endl;
    return 0;
}