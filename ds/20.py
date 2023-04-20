class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        for i in s:
            if len(stk) == 0 or i == "(" or i == "{" or i == "[":
                stk.append(i)
            elif i == ")" and stk[len(stk) - 1] == "(":
                stk.pop()
            elif i == "}" and stk[len(stk) - 1] == "{":
                stk.pop()
            elif i == "]" and stk[len(stk) - 1] == "[":
                stk.pop()
            else:
                return False
        if (len(stk)) == 0:
            return True
        else:
            return False


# fastest
class Solution:
    def isValid(self, s: str) -> bool:
        lst = []
        dic = {"(": ")", "{": "}", "[": "]"}
        left = "([{"
        for i in s:
            if i in left:
                lst.append(dic[i])
            elif lst and lst[-1] == i:
                lst.pop()
            else:
                return False
        return not lst


# lowest memory usage
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False
        contains = []
        endings = {")": "(", "}": "{", "]": "["}
        for char in s:
            if char in (")", "}", "]"):
                if not contains or contains.pop() != endings.get(char):
                    return False
            else:
                contains.append(char)
        return not contains
