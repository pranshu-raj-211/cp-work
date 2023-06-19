class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == mid)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return s;
    }
};

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
            m[i]++;
        }
        m[nums.size()]++;

        for (auto i : m)
        {
            if (i.second == 1)
            {
                return i.first;
            }
        }
        return nums.size();
    }
};