#include <iostream>
#include <vector>
#include <map>

// problem link : https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int element;
        std::map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        for (auto i : map)
        {
            if(i.second > nums.size() / 2)
                element = i.first;
        }

        return element;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {3,2,3,2,2,2};
    std::cout << sol.majorityElement(nums) << std::endl;
}