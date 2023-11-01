#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        //! brute force approach sucks
        int n = nums.size();
        std::vector<int> result;
        std::vector<int> lp(n);
        std::vector<int> rp(n);
        lp[0] = 1;
        for (int i = 1; i < n; i++)
            lp[i] = lp[i - 1] * nums[i - 1];

        rp[n - 1] = 1;
        
        for (int i = n - 2; i >= 0; i--)
            rp[i] = rp[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++)
            result.push_back(lp[i] * rp[i]);
                
        return result;
    }
};
    
int main(){
    Solution sol;
    std::vector<int> nums = {1,2,3,4};
    std::vector<int> result = sol.productExceptSelf(nums);
    for (auto &&i : result)
        std::cout << i << " ";
    return 0;
}