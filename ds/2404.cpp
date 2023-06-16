class Solution
{
public:
    int mostFrequentEven(vector<int> &nums)
    {
        unordered_map<int, int> frequency;
        auto most = INT_MAX;
        auto max = INT_MIN;

        for (auto n : nums)
        {
            if (n % 2 == 0 && ++frequency[n] >= max)
            {
                if (frequency[n] > max || n < most)
                    most = n;
                max = frequency[n];
            }
        }
        return most = INT_MAX ? -1 : most;
    }
};