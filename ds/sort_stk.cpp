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

// gfg
#include <stack>
#include <iostream>

using namespace std;

// Function to sort a stack using recursion
void sortStack(stack<int> &s)
{
    // If the stack is empty, return
    if (s.empty())
        return;

    // Remove the top element of the stack
    int x = s.top();
    s.pop();

    // Sort the remaining elements in the stack using recursion
    sortStack(s);

    // Create two auxiliary stacks
    stack<int> tempStack;

    // Move all elements that are greater than x from the main stack to the tempStack
    while (!s.empty() && s.top() > x)
    {
        tempStack.push(s.top());
        s.pop();
    }

    // Push x back into the main stack
    s.push(x);

    // Move all elements from tempStack back to the main stack
    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main()
{
    // Create a stack
    stack<int> s;

    // Push elements into the stack
    s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    // Sort the stack
    sortStack(s);

    // Print the sorted elements
    cout << "Sorted numbers are: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
