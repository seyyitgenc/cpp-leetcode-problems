#include <iostream>
#include <vector>

// problem link : https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left_column = 0, right_column = height.size() - 1;
        int max_area = 0;
        for (int i = 0; i < height.size(); i++){
            int lenght = right_column - left_column;
            int area = std::min(height[left_column], height[right_column]) * lenght;
            if(area > max_area)
                max_area = area;
            if(height[right_column] > height[left_column])
                left_column++;
            else if(height[left_column] >= height[right_column])
                right_column--;
        }
        return max_area;
    }
};


int main(){
    Solution sol;
    std::vector<int> input = {2,3,4,5,18,17,6};
    // output will be 17
    std::cout << sol.maxArea(input);
}