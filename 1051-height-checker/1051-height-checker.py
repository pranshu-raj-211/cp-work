class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = sorted(heights)
        deviations = 0
        for i in range(len(heights)):
            if heights[i]!=expected[i]:
                deviations+=1
        return deviations