#include <vector>
#include <iostream>
#include <algorithm>

// problem link : https://leetcode.com/problems/max-number-of-k-sum-pairs

// TODO: think about without sorting
class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        int max_operation = 0;
        int p1 = 0, p2 = nums.size() - 1;
        std::sort(nums.begin(),nums.end());
        while (p1 < p2)
        {
            if (nums[p2] >= k)
                p2--;            
            int sum = nums[p1] + nums[p2];
            if (sum == k && p1 != p2){
                p1++;
                p2--;
                max_operation++;
            }
            else if(sum < k){
                p1++;
            }
            else if(sum > k){
                p2--;
            }
        }
        return max_operation;
    }
};

int main(){
    Solution s1;
    std::vector<int> input = {3,1,3,4,3};
    // sorted input = {1,3,3,3,4}
    int k = 6; 
    std::cout << s1.maxOperations(input, k);
    return 0;
}