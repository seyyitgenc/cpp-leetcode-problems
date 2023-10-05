#include <iostream>
#include <vector>
#include <map>

// problem : https://leetcode.com/problems/two-sum/

class Solution {
public:
     std::vector<int> twoSum(std::vector<int> &nums, int target) {
        // 1. approach 2 for loops
        // for (int i = 0; i < nums.size() - 1; i++)
        //     for (int j = i + 1; j < nums.size(); j++)
        //         if ((nums[i] + nums[j]) == target)
        //             return {i , j};
        // return {};
        // 2. approach compliment sol

        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.count(complement) > 0)
                return {map[complement], i};
            map[nums[i]] = i;            
        }
        
        return {};
    }
};

int main(){
    // input
    // 1.case
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    
    Solution sol;
    std::vector<int> answer = {sol.twoSum(nums,target)};
    // output will be [0,1];
    
    std::cout << "[" << answer[0] << "," <<  answer[1] << "]" << std::endl;
    return 0;
}