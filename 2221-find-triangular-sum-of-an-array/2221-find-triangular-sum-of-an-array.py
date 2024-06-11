class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        n = len(nums)
        while n>1:
            newnums = []
            for i in range(n-1):
                newnums.append((nums[i]+nums[i+1])%10)
            nums = newnums
            n-=1
        return nums[0]