#include <vector>
#include <iostream>
#include <algorithm>

// problem link : https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        // dist = {5,4,3,3,3}
        // speed = {1,1,5,3,1}
        // tick = {5,4,1,1,3}
        // sortedTick = {x,1,3,4,5}
        // {x,0,2,3,4}; 

        int size = dist.size();
        std::vector<float>tick (size);
        for (int i = 0; i < size; i++){
            if(speed[i] >= dist[i])
                tick[i] = 1;
            else if(speed[i] < dist[i])
                tick[i] = (float)dist[i] / (float)speed[i];
        }
        
        std::sort(tick.begin(),tick.end());
        int result = 0;
        float min_passed = 0;
        for (int i = 0; i < size; i++)
        {
            if (min_passed < tick[i])
            {
                min_passed++;
                result++;
            }
            else
                break;
        }
        return result;
    }
};

int main(){
    Solution s1;
    std::vector<int> dist   =   {3,5,7,4,5};
    std::vector<int> speed  =   {2,3,6,3,2};
    // tick = {1,1,1,1,2}
    // 
    std::cout << s1.eliminateMaximum(dist,speed);
    return 0;
}