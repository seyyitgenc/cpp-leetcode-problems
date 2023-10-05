#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        int buy = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buy)
                buy = prices[i];
            int profit = prices[i] - buy;
            if (profit > max_profit)
                max_profit = profit;
        }
        return max_profit;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {2,1,4};
    std::cout << sol.maxProfit(nums) << std::endl;
    return 0;
}