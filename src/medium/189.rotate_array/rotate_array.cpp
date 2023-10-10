#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        if (k == nums.size())
            return;
        int end = nums.size() - 1;
        // * 1.  lets reverse the array
        for (int i = 0; i < nums.size() / 2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[nums.size() - i - 1];
            nums[end - i] = temp;
        }
        // note : our k is pivot point
        // * first part is reversing the part before pivot
        for (int i = 0; i < k / 2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[k - i - 1];
            nums[k - i - 1] = temp;
        }
        // * second part is reversing the part after pivot
        for (int i = 0; i < (nums.size() - k) / 2; i++)
        {
            int temp = nums[i + k];
            nums[i + k] = nums[end - i];
            nums[end - i] = temp;
        }
        
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {1,2,3,4,5,6,7}; 
    // reversed : 7,6,5 | 4,3,2,1 
    // our k is pivot lets pivot our third index
    // let's reverse each part
    // 5,6,7 | 1,2,3,4
    // if k = 2 
    // 7,6 | 5,4,3,2,1
    // 6,7, 1,2,3,4,5
    // if k = 6
    // 7,6,5,4,3,2 | 1
    // 2,3,4,5,6,7,1
    sol.rotate(nums, 8);

    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << ", ";
    }
    
    return 0;
}