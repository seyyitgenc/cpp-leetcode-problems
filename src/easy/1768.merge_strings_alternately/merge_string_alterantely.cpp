#include <iostream>
#include <string>

// problem link : https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int p1 = 0,p2 = 0;
        std::string answer = "";
        while (1)
        {
            if (p1 == word1.size() && p2 == word2.size())
                break;
            else{
                if (p1 < word1.size())
                    answer += word1[p1++];
                if (p2 < word2.size())
                    answer += word2[p2++];
            }
            
        }
        return answer;
    }
};

int main(){
    Solution sl;
    std::string word1 = "abc";
    std::string word2 = "pqr";
    std::cout << sl.mergeAlternately(word1, word2) << std::endl;
    return 0;
}