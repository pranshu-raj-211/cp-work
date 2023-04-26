// 2022BCS-053
// Pranshu Raj
// Problem - Valid parentheses problem leetcode 20

// approach used - pushing open parentheses into stack, popping when corresponding closing
// parentheses are found and returning false for any anomaly

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<char> stack;
    // stack for storing elements
    for (int i = 0; i < s.size(); i++)
    {
        // assuming input string to contain only parentheses such as (), [] and {}
        if (stack.empty())
        {
            stack.push(s[i]);
        }
        else
        {
            // if stack is not empty
            if (stack.top() == '}' || stack.top() == '}' || stack.top() == ']')
                return false; // cannot insert ')',']','}' into the stack
            else if (s[i] == ')' && stack.top() == '(')
                stack.pop(); // found matching ()
            else if (s[i] == ']' && stack.top() == '[')
                stack.pop(); // found matching []
            else if (s[i] == '}' && stack.top() == '{')
                stack.pop(); // found matching {}
            else
                stack.push(s[i]); // found opening parentheses, push into stack
        }
    }

    if (stack.empty())
    {
        cout << "True";
        return true;
    } // stack should be empty if all parentheses are balanced
    else
    {
        cout << "False";
        return false;
    }
}

int main()
{
    // driver code
    string s;

    cout << "Enter string to check\n";
    cin >> s;
    isValid(s);
    return 0;
}