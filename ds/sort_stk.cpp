#include <iostream>
#include <stack>
using namespace std;

stack<int> sort_stk(stack<int> s)
{
    stack<int> temp;
    while (!s.empty())
    {
        int tmp = s.top();
        s.pop();
        while (!temp.empty() && temp.top() > tmp)
        {
            s.push(temp.top());
            temp.pop();
        }
        temp.push(tmp);
    }
    return temp;
}

stack<int> input_stk(int n)
{
    stack<int> stk;
    int x;

    cout << "Enter stack elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        stk.push(x);
    }
    return stk;
}

int main()
{
    stack<int> input;
    int n;
    cout << "Enter size of stack\n";
    cin >> n;
    input = input_stk(n);
    // This is the temporary stack
    stack<int> tmpStack = sort_stk(input);
    cout << "Sorted numbers are:\n";

    while (!tmpStack.empty())
    {
        cout << tmpStack.top() << " ";
        tmpStack.pop();
    }
}