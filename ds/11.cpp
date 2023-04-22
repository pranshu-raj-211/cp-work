class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxh = 0, n = height.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            if (height[i] > height[j])
            {
                maxh = max(maxh, (j - i) * height[j]);
                j--;
            }
            else
            {
                maxh = max(maxh, (j - i) * height[i]);
                i++;
            }
        }
        return maxh;
    }
};
