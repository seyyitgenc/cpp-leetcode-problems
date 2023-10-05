#include <vector>
#include <iostream>

// problem link : https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {        
        int comp = m - 1;
        int iter1 = m + n - 1;
        int iter2 = n - 1;
        
        while (iter2 >= 0) // if there is still numbers in list 2
        {
            if (comp >= 0 && nums1[comp] > nums2[iter2]) // if there is still elements left to compare and if nums1 index > nums2 index
                nums1[iter1--] = nums1[comp--];
            else
                nums1[iter1--] = nums2[iter2--];
            
        }
        
        for (int i = 0; i < m + n; i++)
        {
            std::cout << nums1[i] << std::endl;
        }
    }
};

int main(){
    Solution sol;
    std::vector<int> nums1({4,5,6,0,0});
    std::vector<int> nums2({1,2,3});
    sol.merge(nums1,3,nums2,3);
}