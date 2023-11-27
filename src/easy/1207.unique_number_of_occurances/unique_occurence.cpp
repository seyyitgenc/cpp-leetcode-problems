#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// problem link : https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int,int> map; // value , count
        std::unordered_set<int> counts;
        for (int i = 0; i < arr.size(); i++)
            map[arr[i]]++;
        for (auto &&i : map)
        {
            if (counts.contains(i.second))
                return false;
            counts.insert(i.second);
        }
        return true;
    }
};

int main(){

    Solution s1;
    std::vector<int> input = {1,2,4,5,6,66,6,66,2,1,1,3};
    std::cout << s1.uniqueOccurrences(input) << std::endl;
    return 0;
}