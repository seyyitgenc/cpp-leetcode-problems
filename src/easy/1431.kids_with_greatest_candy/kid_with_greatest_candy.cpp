#include <vector>
#include <iostream>

// problem link : https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> result;
        int greatest = candies[0];
        for (int i = 1; i < candies.size(); i++)
        {
            if (candies[i] >= greatest)
                greatest = candies[i];
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= greatest)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};

int main(){
    Solution s1;
    std::vector<int> candies = {2,3,5,1,3};
    int extra_candies = 3;
    std::vector<bool> result = s1.kidsWithCandies(candies, extra_candies);

    for (auto i : result)
        std::cout << i <<  " ";
    return 0;
}