#include <string>
#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int index = -1;
        for (int i = 0; i < haystack.size() - needle.size(); i++)
        {
            std::string sub = haystack.substr(i,needle.size());
            if (sub == needle)
            {
                index = i;
                break;
            }
        }
        return index;
    }
};
    
int main(){
    Solution sol;
    std::string str1 = "sadbutsad";
    std::string str2 = "sad";
    std::cout << sol.strStr(str1,str2);
}