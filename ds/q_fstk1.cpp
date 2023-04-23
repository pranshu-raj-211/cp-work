#include <iostream>
#include <stack>

using namespace std;
// costly enqueue method
struct qfs
{
    stack<int> s1, s2;
    void push(int x)
    {
        s1.push(x);
    }
    void enQueue(int x)
    {
        // enqueue operation adds elements to the queue
        while (!s1.empty())
        {
            // emptying contents of first stack into second
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);
        // adding new element to the now empty s1 stack
        while (!s2.empty())
        {
            // adding back elements of second stack to first stack
            s1.push(s2.top());
            s2.pop();
            // elements are now in lifo order
        }
    }

    int deQueue()
    {
        // while(!s1.empty())
        // {
        //     cout<<s1.top();
        //     s1.pop()
        // }

        if (s1.empty())
        {
            // check for empty stack
            cout << "Empty stack";
            exit(0);
        }

        // removing one element from queue and returning it
        int x = s1.top();
        s1.pop();
        return (x);
    }
};

int main()
{
    // driver code to run the whole thing
    qfs q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
}

// enQueue(q,  x)
//   1) Push x to stack1 (assuming size of stacks is unlimited).
// Here time complexity will be O(1)

// deQueue(q)
//   1) If both stacks are empty then error.
//   2) If stack2 is empty
//        While stack1 is not empty, push everything from stack1 to stack2.
//   3) Pop the element from stack2 and return it.
// Here time complexity will be O(n)