#include <iostream>
#include <vector>
#include <map>

// problem link : https://leetcode.com/problems/house-robber/

// !not yet solved

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int size = nums.size() - 1;
        int money = 0;
        int max = nums[0];
        // store robbed houses as an index number
        std::map<int,int> robbed;
        for (int i = 0; i < size; i++)
        {
            std::map<int,int> robbed;
            for (int j = 0; j < size; j++)
            {
                if (max > nums[j]){
                    max = nums[j];
                    robbed[nums[j]] = nums[j];
                }
            }
            
            // int j = i + 2;
            // if (j  >= size)
            //     j = 0;
            // else if (j  <= 0)
            //     j = size;
            
            
        }
        return money;
    }
};

int main(){
    Solution sol;
    std::vector<int> input = {1,2,3,4};
    std::cout << sol.rob(input);
    return 0;
}