
#include <string>
#include <iostream>
#include <stack>


class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> myStack;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s.at(i) == '[' || s.at(i) == '{' || s.at(i) == '(')
                myStack.push(s.at(i));
            else {
                if (myStack.size() > 0)
                {
                    if (s.at(i) == ']' && myStack.top() == '[')
                    {
                        myStack.pop();
                    }
                    else if (s.at(i) == ')' && myStack.top() == '(')
                    {
                        myStack.pop();
                    }
                    else if (s.at(i) == '}' && myStack.top() == '{')
                    {
                        myStack.pop();
                    }
                    else return false;
                }
                else return false;

            }
        }
        return myStack.size() > 0 ? false : true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    auto result = sol.isValid("([[]])");
    std::cout << result << std::endl;
    return 0;
}
