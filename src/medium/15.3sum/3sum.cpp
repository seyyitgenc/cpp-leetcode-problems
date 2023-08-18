#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

// problem link : https://leetcode.com/problems/3sum/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        // ! KEY THING HERE IS THE SORT PART
        std::sort(nums.begin(),nums.end());
        std::set<std::vector<int>> set;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            // -----------
            // BRUTE FORCE
            // for (int j = i + 1; j < nums.size() - 1; j++)
            // {
            //     for (int k = j + 1; k < nums.size(); k++)
            //     {
            //         if (i != j && i != k && j !=k)
            //         {
            //             std::vector<int> triplets;
            //             if (nums[i] + nums[j] + nums[k] == 0)
            //             {
            //                 triplets.push_back(nums[i]);
            //                 triplets.push_back(nums[j]);
            //                 triplets.push_back(nums[k]);
            //                 set.insert(triplets);
            //                 // result.push_back(triplets);
            //             }
                        
            //         }
            //     }
                
            // }

            // -----------------------
            // MORE OPTIMIZED APPROACH
            
            int low = i+1; 
            int high = nums.size() - 1;
            while (low < high)
            {
                if (nums[i] + nums[low] + nums[high] < 0)
                    low++;
                else if (nums[i] + nums[low] + nums[high] > 0)
                    high--;
                else{
                    set.insert({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                }                                
            }
            
        }
         for (auto &i : set)
        {
            result.push_back(i);
        }
        return result;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums = {-1,0,1,2,-1,-4} ;
    
    sol.threeSum(nums);

    return 0;

}