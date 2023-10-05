#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

// problem link :  https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {       
        std::unordered_map<int,int> map;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.contains(nums[i]))            
                return true;

            map[nums[i]] = nums[i];
        }
        return false;
        // std::set<int> set; // stores unique values

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (set.contains(nums[i]))
        //         return true;
        //     set.insert(nums[i]);
        // }
        
        // return false;
    }
};

int main(){

    Solution sol;
    std::vector<int> nums = {1,2,3,4}; 
    std::cout << sol.containsDuplicate(nums) << std::endl;
}