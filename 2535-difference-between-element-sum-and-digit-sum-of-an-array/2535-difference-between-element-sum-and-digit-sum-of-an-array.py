class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        ele_sum,dig_sum=0,0
        for i in nums:
            ele_sum+=i
            x=i
            while(x>0):
                dig_sum+=x%10
                x=x//10
                
        return abs(ele_sum-dig_sum)