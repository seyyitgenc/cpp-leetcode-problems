#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// problem link : https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums,int target) {
        std::sort(nums.begin(),nums.end());
        int result;
        int diff = INT_MAX;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high)
            {
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == target)
                    return sum;
                int newDiff = sum - target;
                if (newDiff > 0)
                    high--;
                if(newDiff < 0)
                    low++;
                if ((abs(newDiff) <= abs(diff)))
                {
                    diff = newDiff;
                    result = sum;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {2,3,8,9,10} ;
    std::cout << sol.threeSumClosest(nums,16);
    return 0;

}