#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int size = height.size();
        int leftColumn = 0 , rightColumn = size - 1;
        int maxArea = 0;

        for (int i = 1; i < size - 1; i++)
        {
            if (height[leftColumn] <= height[rightColumn])
            {
                int diff = rightColumn - leftColumn;
                int newArea = height[leftColumn] * diff;
                if (newArea > maxArea)
                    maxArea = newArea;
                leftColumn++;
            }
            if (height[leftColumn] >= height[rightColumn] )
            {
                int diff = rightColumn - leftColumn;
                int newArea = height[rightColumn] * diff;
                if (newArea > maxArea)
                    maxArea = newArea;
                rightColumn--;
            }
        }
        return maxArea;
    }
};


int main(){
    Solution sol;
    std::vector<int> input = {2,3,4,5,18,17,6};
    // output will be 17
    std::cout << sol.maxArea(input);
}