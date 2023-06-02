"""
Given an array of integers nums, return the number of good pairs.

A pair (i, j) is called good if nums[i] == nums[j] and i < j.
"""


class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        count = 0
        for j in range(len(nums)):
            for i in range(j):
                if nums[i] == nums[j]:
                    count += 1
        return count
