#include <iostream>
#include <vector>
#include <map>
class Solution {
public:
     std::vector<int> twoSum(std::vector<int> &numbers, int target) {
        std::map<int, int> r;
        std::vector<int> rr;
        for (int i = 0; i < numbers.size() - 1; i ++) {
            if (r.find(numbers[i]) == r.end()) { // if not exist
                r[numbers[i]] = i;  // add it to the map
            }
            int j, num = target - numbers[i];
            if ((r.find(num) != r.end()) && ((j = r[num]) < i)) {
                rr.push_back(j);
                rr.push_back(i);
                return rr;
            }
        }
        return rr;
    }
};

int main(){
    // input
    // 1.case
    // std::vector<int> nums = {2,7,11,15};
    // int target = 9;
    
    // 2. case
    std::vector <int>nums = {2,3,4};
    int target = 6;

    // 3. case
    // std::vector <int>nums = {3,3};
    // int target = 6;

    Solution sol;
    std::vector<int> answer = {sol.twoSum(nums,target)};
    // output will be [0,1];
    
    std::cout << "[" << answer[0] << "," <<  answer[1] << "]" << std::endl;
    return 0;
}