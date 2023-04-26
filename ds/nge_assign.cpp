// 2022BCS-053
// Pranshu Raj
// Problem - to check for next greater element using a stack

// approach used - storing indexes of elements in a stack which do not have a greater
// element after them

#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s; // declaring an stack
    int n;
    cout << "Enter size of input array";
    cin >> n;

    int in[n], out[n]; // declaring two arrays for input and output

    // taking inputs
    cout << "\nEnter array elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    for (int i = 0; i <= 2 * n - 1; i++) // traversing through the array
    {
        while (!s.empty() && in[s.top()] < in[i % n])
        {
            // checking the condition for next greater element
            out[s.top()] = in[i % n];
            s.pop(); // removing top(index) from stack
        }
        if (i < n)
        {
            s.push(i); // pushing index into stack
        }
    }

    while (!s.empty())
    { // assign -1 to the indexes which do not have any next greater element
        out[s.top()] = -1;
        s.pop();
    }

    cout << "\nThe solution is :\n";
    for (int i = 0; i < n; i++)
    {
        cout << out[i] << "  ";
    }
    return 0;
}