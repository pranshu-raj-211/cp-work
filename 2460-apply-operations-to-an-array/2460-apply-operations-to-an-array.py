class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n-1):
            if nums[i]==nums[i+1]:
                nums[i], nums[i+1] = 2*nums[i], 0
        
        i=0
        for j in range(n):
            if nums[j]!=0:
                nums[i]=nums[j]
                i+=1
        while i<n:
            nums[i]=0
            i+=1
        return nums
    