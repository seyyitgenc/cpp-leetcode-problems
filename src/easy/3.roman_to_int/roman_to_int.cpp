#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s){
        int answer = 0;
        std::unordered_map<char,int> map;        
        map['I'] =  1;
        map['V'] =  5;
        map['X'] =  10;
        map['L'] =  50;
        map['C'] =  100;
        map['D'] =  500;
        map['M'] =  1000;
        for (auto i = s.begin(); i < s.end(); i++)
        {
            if (map[*i] < map[*(i+1)])
                answer -=  map.at(*i);   
            else
                answer +=  map.at(*i);   
        }
        return answer;
    }
};

int main(){
   
   std::string s = "MCMXCIV";
   Solution sol;
   std::cout << sol.romanToInt(s);
   return 0;
}