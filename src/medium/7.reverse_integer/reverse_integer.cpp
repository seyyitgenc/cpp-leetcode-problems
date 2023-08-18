#include <iostream>

// problem link : https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while (x != 0)
        {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        if (reverse > INT_MAX || reverse < INT_MIN)
            return 1;
        return reverse;
    }
};

int main(){
    Solution sol;
    int input = 1534236469;
    // expected output : 321;
    std::cout << sol.reverse(input);
    return 0;

}