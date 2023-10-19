#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int first = 0, last = s.size() - 1;
        for (int i = 0 ; i < s.length(); i++)
        {
            if (s[last] == ' ')
            {
                last--;
            }
            if (s[i] != ' ' && i > 0)
            {
                if (s[i - 1] == ' ')
                    first = i;
            }
        }
     return last - first + 1;   
    }
};

int main(){
    Solution sol;
    std::string str = " joyboy ";
    std::cout << sol.lengthOfLastWord(str) << std::endl;
    return 0;
}