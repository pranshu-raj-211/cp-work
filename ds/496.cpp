// brute force
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            int ng = -1;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    int index = j;
                    while (index != nums2.size())
                    {
                        if (nums2[index] > nums1[i])
                        {
                            ng = nums2[index];
                            break;
                        }
                        index++;
                    }
                }
            }
            nums1[i] = ng;
        }
        return nums1;
    }
};

// faster method
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        int ctr = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            auto x = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            for (int j = x + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums1[i])
                {
                    ctr++;
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if (ctr == 0)
            {
                ans.push_back(-1);
            }
            ctr = 0;
        }
        return ans;
    }
};