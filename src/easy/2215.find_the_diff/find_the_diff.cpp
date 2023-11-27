#include <iostream>
#include <vector>
#include <unordered_set>

// problem link : https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_set<int> set1(nums1.begin(),nums1.end());
        // set1 = 1,2,3
        std::unordered_set<int> set2(nums2.begin(),nums2.end());
        // set2 = 1,2,4,6
        std::vector<int> diff1,diff2;

        for (auto &&i : set1)
        {
            if (set2.count(i) == 0)
                diff1.push_back(i);
        }
        
        for (auto &&i : set2)
        {
            if (set1.count(i) == 0)
                diff2.push_back(i);
        }
        return {diff1,diff2};
    }
};

int main(){
    Solution s1;
    std::vector<int> input1 = {1,2,3,3};
    std::vector<int> input2 = {1,2,4,6};

    std::vector<std::vector<int>> result = s1.findDifference(input1,input2);
    for (auto &&item : result)
    {
        for (auto &&i : item)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    
    return 1;
}