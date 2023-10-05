#include <iostream>
#include <vector>
#include <map>

// problem link : https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        
        // ! non-optimized approach but it's good
        // note : we can use boyer-moore algorithm
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;

        std::vector<int> result;
        for (auto it : map)
        {
            if (it.second > nums.size() / 3)
            {
                result.push_back(it.first);
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {3,2,3,2};
    std::vector<int> answer = sol.majorityElement(nums);
    for (int i = 0; i < answer.size(); i++)
        std::cout << answer[i] <<  ", ";
}