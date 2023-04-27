#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s, l;
    // declaring stack
    cout << "Enter length of array";
    int n;
    cin >> n;
    int A[n];
    bool flag = true;
    int fmax, smax, f;

    cout << "\nEnter array elements";
    for (int i = 0; i < n; i++)
    {
        // taking array inputs
        cin >> A[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
        {
            // first case
            s.push(A[i]);
            if (s.size() == 1 && flag == true)
            {
                l.push(s.top());
                flag = false;
            }
            f = s.top();
            if (f >= l.top())
            {
                l.push(f);
            }
        }
        else if (A[i] == -1)
        {
            // second case
            if (!s.empty())
            {
                if (l.top() == s.top())
                {
                    l.pop();
                    s.pop();
                }
            }
        }
        else if (A[i] == -2)
        {
            // third case
            if (!s.empty())
            {
                s.top()++;
                l.top()++;
            }
        }
        else if (A[i] == -3)
        {
            // fourth case
            if (s.size() >= 2)
            {
                l.pop();
                cout << l.top();
            }
            else
                cout << -1;
        }
    }
}