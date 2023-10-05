#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/house-robber/


// ! not yet solved

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int size = nums.size() - 1;
        int money = 0;
        for (int i = 0; i < 2; i++)
        {
            int temp = 0;
            for (int j = i; j < nums.size(); j = j + 2)
            {
                temp += nums[j];
            }
            if (temp >= money)
                money = temp;
        }
        return money;
    }
};

int main(){
    Solution sol;
    std::vector<int> input = {1,2,3,4};
    std::cout << sol.rob(input);
    return 0;
}