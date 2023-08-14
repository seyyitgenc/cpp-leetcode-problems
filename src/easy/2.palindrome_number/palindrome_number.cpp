#include <iostream>
#include <vector>
#include <math.h>

class Solution {
public:
    bool isPalindrome(int x){
        long int temp = x;
        long int palindrome = 0;
        int i = 0;
        if (x < 0)// if x is smaller then 0 it always fails
            return false;
        
        while (temp != 0)
        {
            palindrome = palindrome * 10 + (temp % 10);
            temp /= 10;
            i++;
        }
        if (palindrome == x)
            return true;
        return false;        
    }
};

int main(){
    // input x = 121;
    // output true   
    int x = -121;
    Solution sol;
    std::cout << sol.isPalindrome(x);
}