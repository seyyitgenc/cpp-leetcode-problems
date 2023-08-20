#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // ! my bad approach
        // std::vector<std::vector<std::string>> result;
        // std::map<int,std::string> int_values_of_string;
        // for (int i = 0; i < strs.size(); i++)
        // {
        //     int int_value_of_string = 0;
        //     for (auto j = strs[i].begin(); j < strs[i].end(); j++)
        //     {
        //         int_value_of_string += *j - '0';
        //     }
        //     int_values_of_string[int_value_of_string] = strs[i];
        // }
        // for (auto &&values : int_values_of_string)
        // {
        //     std::vector<std::string> anagrams;
        //     for (int i = 0; i < strs.size(); i++)
        //     {
        //         int int_value_of_string = 0;
        //         auto iter = strs[i].begin(); 
        //         while (iter != strs[i].end())
        //         {
        //             int_value_of_string += *iter - '0';
        //             iter++;
        //         }
        //         if (int_value_of_string == values.first)
        //             anagrams.push_back(strs[i]);
        //     }                
        //     result.push_back(anagrams);   
        // }
        //  return result;
        
        std::map<std::string, std::vector<std::string>> map;
        std::vector<std::vector<std::string>> result;
        for (auto i : strs)
        {
            std::string word = i;
            std::sort(word.begin(),word.end());
            map[word].push_back(i);
        }
        for (auto i : map)
            result.push_back(i.second);
        
        return result;
    }
};

int main(){
    Solution sol;
    std::vector<std::string> strs = {"cab","tin","pew","duh","may","ill","buy","bar","max","doc"};
    std::vector<std::vector<std::string>> result =  sol.groupAnagrams(strs);

    for (int i = 0; i < result.size(); i++)
    {
        for (auto j = result[i].begin(); j < result[i].end(); j++)
        {
            std::cout << *j << " "; 
        }
        std::cout << "\n";
    }
    
    return 0;
}