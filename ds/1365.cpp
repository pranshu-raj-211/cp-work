class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int map[101] = {};
        for (auto num : nums)
        {
            map[num]++;
        }
        int len = nums.size();
        vector<int> res(len);
        for (int num = 0; num < len; num++)
        {
            res[num] = accumulate(map, map + nums[num], 0);
        }
        return res;
    }
};

// sample solution

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> visited = vector<int>(102, 0);
        for (auto num : nums)
            visited[num + 1]++;
        for (int i = 1; i < 102; i++)
        {
            visited[i] += visited[i - 1];
        }
        for (int i = 0; i < nums.size(); i++)
            nums[i] = visited[nums[i]];
        return nums;
    }
};