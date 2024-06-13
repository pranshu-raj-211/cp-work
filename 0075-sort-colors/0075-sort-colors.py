class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # basic count sort
        
        # ordering in ascending order, ie, 0,1,2
        count = [0]*3 # count occurences of 0,1,2
        for i in nums:
            count[i]+=1
        nums.clear()
        for i in [0,1,2]:
            nums.extend([i]*count[i])