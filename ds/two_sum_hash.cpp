#include <iostream>
#include <unordered_map>

using namespace std;

bool check(int *arr, int sum, int n);

int main()
{
    int n, sum = 0;
    cout << "Length of arr";
    cin >> n;
    int arr[n];
    cout << "\nEnter array elements";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    cout << "\nEnter sum to check for ";
    cin >> sum;

    bool present = check(arr, sum, n);
    if (present)
        cout << "true";
    else
        cout << "false";
}

bool check(int *arr, int sum, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int complement = sum - *(arr + i);
        if (m.find(complement) == m.end())
            m[*(arr + i)] = i;
        else
            return true;
    }
    return false;
}