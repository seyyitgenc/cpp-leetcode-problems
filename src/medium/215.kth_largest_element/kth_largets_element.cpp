#include <iostream>
#include <vector>
#include <queue>

// problem link : https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater_equal<int>> queue(nums.begin(),nums.begin() + k);

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > queue.top())
            {
                queue.pop();
                queue.push(nums[i]);
            }
        }
        return queue.top();
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    std::cout << sol.findKthLargest(nums, k);
}