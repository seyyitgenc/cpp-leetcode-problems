#include <vector>
#include <iostream>

// problem link : https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        //  // ! brute force
        // for (int i = 0; i < nums.size() - 1; i++)
        // {
        //     for (int j = i + 1; j < nums.size(); j++)
        //     {
        //         if (nums[i] == 0 && nums[j] != 0)
        //         {
        //             nums[i] = nums[j];
        //             nums[j] = 0;
        //         }
        //     }
        // }
        //
        
        // // ! 2. approach
        // int j = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == 0)
        //         j++;
        //     else if(j > 0){
        //         nums[i - j] = nums[i];
        //         nums[i] = 0; 
        //     }
            
        // }
        // ! 3. approach

        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0 && nums[j] == 0)
                std::swap(nums[i],nums[j]);
            if (nums[j] != 0)
                j++;
        }
        
    }
};

int main(){
    Solution s1;
    std::vector<int> nums = {1,0,0,3,12};
    s1.moveZeroes(nums);
    for (auto i : nums)
        std::cout << i << " ";
    return 0;
}