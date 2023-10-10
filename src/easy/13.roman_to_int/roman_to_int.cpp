#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char,int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int result = 0;
        for (auto i = s.begin(); i < s.end(); i++)
        {
            if (map[*i] < map[*(i + 1)])
                result -= map[*i]; 
            else
                result += map[*i];
        }
        return result;
    }
};

int main(){
    Solution sol;
    std::cout << sol.romanToInt("MCMXCIV");
    return 0;
}