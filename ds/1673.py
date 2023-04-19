class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        wealth = []
        for i in range(len(accounts)):
            sum = 0
            for j in range(len(accounts[0])):
                sum += accounts[i][j]
            wealth.append(sum)
        return max(wealth)
