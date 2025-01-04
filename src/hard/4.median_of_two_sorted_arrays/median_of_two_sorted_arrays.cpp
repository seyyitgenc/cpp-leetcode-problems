#include <iostream>

#include <vector>
#include <cmath>

// problem link : https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> sorted(nums1.size() + nums2.size());

        int i = 0, j = 0, k = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
        
            // Pick smaller of the two current
            // elements and move ahead in the
            // array of the picked element
            if (nums1[i] < nums2[j])
                sorted[k++] = nums1[i++];
            else
                sorted[k++] = nums2[j++];
        }

        // if there are remaining elements of
        // the first array, move them
        while (i < n1)
            sorted[k++] = nums1[i++];

        // Else if there are remaining elements of
        // the second array, move them
        while (j < n2)
            sorted[k++] = nums2[j++];
            
        int median = std::ceil(sorted.size() / 2.0);
        if (median % 2 == 0)
        {
            return (double(sorted[median - 1] + sorted[median])) / 2.0;
        }
        else{
            return sorted[median - 1];
        }
    }
};

int main(){
    Solution sol;
    std::vector<int> nums1;
    std::vector<int> nums2 = {3};
    std::cout << "result is " << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
    return 0;

}