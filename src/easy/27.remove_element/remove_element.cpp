#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/remove-element/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[i] = nums[k];
                k++;
            }   
        }
        return k;
    }
};


int main(){
    Solution sol;
    std::vector<int> nums({3,2,2,3});

    int k =  sol.removeElement(nums,3);
    std::cout << "k value = " << k << std::endl;
    for (int i = 0; i < k; i++)
    {
        std::cout << ", " << nums[i];
    }   
}