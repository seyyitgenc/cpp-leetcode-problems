#include <iostream>
#include <vector>
#include <unordered_map>

// problem link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // ! if array is not sorted this will be the approach
        
        // std::unordered_map<int,int> map;
        // int k = 0;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (!map.contains(nums[i]))
        //     {
        //         nums[k] = nums[i];
        //         k++;
        //     }
        //     map[nums[i]] = nums[i];    
        // }
        // return k;

        // ! but in the problem it says array is sorted soooo

        int k = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[k] = nums[i];
                k++;
            }            
        }
        return k;
        
    }
};


int main(){
    Solution sol;
    std::vector<int> nums({3,2,2,3,3,3,3});

    int k =  sol.removeDuplicates(nums);
    std::cout << "k value = " << k << std::endl;
    for (int i = 0; i < k; i++)
    {
        std::cout << ", " << nums[i];
    }   
}