#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// problem link : https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        // ! we know that words consist of only lowercase english letters

        if (word1.size() != word2.size()) return false; // we can't attend the close strings        

        int m = word1.size();
        int n = word2.size();
        std::vector<int> freq1(26),freq2(26);

        // ! we alraedy know words are equal size so wen can calculate freq
        // ! of both words in one for loop

        for (int i = 0; i < m; i++)
        {
            freq1[word1[i] - 'a']++; 
            freq2[word2[i] - 'a']++;
        }

        // lets perfom basic set calculation 
        for (int i = 0; i < 26; i++)
        {
            // ! both words need to have same characters
            if (freq1[i] != 0 && freq2[i] == 0) return false; // this performs basic set check
            if (freq1[i] == 0 && freq2[i] != 0) return false; // this performs basic set check
        }
        // * now our words contains same characters lets check frequencies

        std::sort(freq1.begin(),freq1.end());
        std::sort(freq2.begin(),freq2.end());

        if (freq1 != freq2) return false;
        return true;
    }
};

int main(){
    Solution s1;
    std::string input1 = "abbzzca";
    std::string input2 = "babzzcz";
    std::cout << s1.closeStrings(input1, input2);
    return 0;
}