#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        // // this is O(n^2)
        // double max_avarage = INT_MIN;
        // for (int i = 0; i <= nums.size() - k; i++)
        // {
        //     double sum = 0;
        //     int j = 0;
        //     while (j < k)
        //     {
        //         sum += nums[i + j];
        //         j++;
        //     }
            
        //     double avarage = sum / k;
        //     if (avarage >= max_avarage)
        //         max_avarage = avarage;
        // }
        // return max_avarage;

        // lets make it O(n)
        double sum = 0;
        double max_sum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (i >= k)
                sum -= nums[i - k];
            if (i + 1 >= k)
                max_sum = std::max(max_sum,sum);
            
        }
        return max_sum / k;
    }
};


int main(){
    Solution s1;
    std::vector<int> input = {9,7,3,5,6,2,0,8,1,9};
    int k = 6;
    std::cout << "result : " << s1.findMaxAverage(input,k);
    return 0;
}