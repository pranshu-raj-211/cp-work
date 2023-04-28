#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    // driver code
    string s;

    cout << "Enter string to check\n";
    cin >> s;
    cout << s;
    return 0;
}

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 0)
        {
            st.push(A[i]);
        }
        else if (A[i] == -1)
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (A[i] == -2)
        {
            if (!st.empty())
            {
                st.top()++;
            }
        }
        else if (A[i] == -3)
        {
            if (st.size() >= 2)
            {
                int last = st.top();
                st.pop();
                int second_last = st.top();
                st.pop();
                st.push(last + second_last);
            }
        }
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;

        return 0;
    }