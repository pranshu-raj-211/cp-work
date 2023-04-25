// Next greater element problem leetcode 496
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans; // stack to store answer
        for (int i = 0; i < nums1.size(); i++)
        {
            // iterating through nums1
            int ng = -1;
            // variable to store next greater element
            for (int j = 0; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    // working on corresponding element
                    int index = j;
                    while (index != nums2.size()) // going from j to end of nums2
                    {
                        if (nums2[index] > nums1[i])
                        {
                            // check for next greater element, break if found
                            ng = nums2[index];
                            break;
                        }
                        index++;
                    }
                }
            }
            ans.push_back(ng);
            // pushing answer into stack
        }
        return ans;
    }
};
