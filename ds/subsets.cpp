#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans);

int main()
{
    vector<int> nums;
    int n, x;
    cout << "Enter number to elements ";
    cin >> n;
    cout << "\nEnter array elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        nums.push_back(x);
    }

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    // add func to print elements
}

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}
