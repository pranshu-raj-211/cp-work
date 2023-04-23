#include <iostream>
#include <stack>

// costly dequeue method, better than first try
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // adding elements to first stack
        s1.push(x);
    }

    int deQueue()
    {
        // function for removal of elements
        if (s1.empty() && s2.empty())
        {
            cout << "Both stacks are empty";
            exit(0);
        }

        if (s2.empty())
        {
            // push elements of first stack into second
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // pop the top element of the second stack
        int x = s2.top();
        s2.pop();
        return x;
    }
};
int main()
{
    // driver code
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';

    return 0;
}

// enQueue(x)
//   1) Push x to stack1.

// deQueue:
//   1) If stack1 is empty then error.
//   2) If stack1 has only one element then return it.
//   3) Recursively pop everything from the stack1, store the popped item
//     in a variable res,  push the res back to stack1 and return res

// recursive queue

// enQueue(x)
//   1) Push x to stack1.

// deQueue:
//   1) If stack1 is empty then error.
//   2) If stack1 has only one element then return it.
//   3) Recursively pop everything from the stack1, store the popped item
//     in a variable res,  push the res back to stack1 and return res