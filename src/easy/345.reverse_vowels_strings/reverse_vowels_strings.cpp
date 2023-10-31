#include <string>
#include <iostream>
#include <unordered_set>
class Solution {
public:
    std::string reverseVowels(std::string s) {
        // std::string str_vowels = "aeiouAEIOU";
        // std::unordered_set<char> set_vowels;

        int p1 = 0, p2 = s.size() - 1;
        while (p1 < p2)
        {
            if (is_wowel(s[p1]) && is_wowel(s[p2]))
            {
                std::swap(s[p1],s[p2]);
                p1++;
                p2--;
            }
            else if (!is_wowel(s[p1]))
                p1++;
            else
                p2--;
        }
        return s;
    }
    // more optimized approach
    bool is_wowel(char t){
        if (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' || 
        t == 'A' || t == 'E' || t == 'I' || t == 'O' || t == 'U')
            return true;
        false;
    }
};

int main(){
    Solution s1;
    std::string str = "aA";
    // output : leotcede
    std::cout << s1.reverseVowels(str);
}