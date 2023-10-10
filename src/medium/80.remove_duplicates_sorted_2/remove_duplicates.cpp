#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // int k = 1;
        // int count = 1;
        // bool is_swap = true;
        // for (int i = 0 ; i < nums.size() - 1; i++)
        // {
        //     if (is_swap)
        //     {
        //         if (nums[i] == nums[i + 1]){
        //             std::cout << nums[i] << ", " << nums[i + 1] <<  std::endl; 
        //             is_swap = false;
        //         }
        //         else if ((nums[i] + 1) != nums[i+1]){
        //             std::cout << nums[i + 1] << std::endl;
        //             is_swap = false;
        //         }
        //     }
        //     if (nums[i] != nums[i + 1])
        //     {
        //         is_swap = true;
        //     }
        // }
        
        // return k;

        int k = 1;
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                count++;
            if (nums[i] != nums[i - 1])
                count = 0;
            if(nums[i] != nums[i - 1] || count < 2){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
int main(){
    Solution sol;
    std::vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int k = sol.removeDuplicates(nums);
    for (int i = 0; i < k; i++)
    {
        std::cout <<  nums[i] << ", " << std::endl;
    }

    return 0;
}
