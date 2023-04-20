class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        for i in range(len(prices)):
            for j in range(i + 1, len(prices)):
                if prices[j] <= prices[i]:
                    prices[i] -= prices[j]
                    break
        return prices


# fastest
class Solution:
    def finalPrices(self, p: List[int]) -> List[int]:
        s = []
        l = []
        for i in range(len(p) - 1, 0, -1):
            if len(s) == 0:
                l.append(p[i])
                if p[i] <= p[i - 1]:
                    s.append(p[i])
            else:
                l.append(p[i] - s[-1])
                s.append(p[i])
                while len(s) != 0 and s[-1] > p[i - 1]:
                    s.pop()
        if len(s) == 0:
            l.append(p[0])
        else:
            l.append(p[0] - s[-1])
        for i in range(len(l) // 2):
            l[i], l[-i - 1] = l[-i - 1], l[i]
        return l
