// arr of size n having distinct elements

// Pranshu Raj
// 2022BCS-053
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nge(int arr[], int n)
{

    pair<int, int> p;
    stack<pair<int, int>> s;
    p.first = arr[n - 1];
    int max = -1;
    p.second = max;
    s.push(p);

    for (int i = n - 2; i >= 0; i--)
    {
        // max = max > arr[i + 1] ? max : arr[i + 1];
        if (arr[i + 1] > arr[i])
            max = arr[i + 1];

        p.first = arr[i];
        p.second = max;
        s.push(p);
    }
    cout << "output" << endl;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> out;
        out = s.top();
        cout << out.second << ",";
        s.pop();
    }
}
int main()
{
    int n;
    cout << "Enter length of array ";
    cin >> n;
    int x, arr[n];

    cout << "\nEnter array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
    }

    nge(arr, n);
}