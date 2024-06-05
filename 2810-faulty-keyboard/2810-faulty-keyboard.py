class Solution:
    def finalString(self, s: str) -> str:
        for i in range(len(s)):
            if s[i] == 'i':
                if i <len(s)-1:
                    s = s[i-1::-1]+' '+s[i+1:]
                else:
                    s = s[i-1::-1]
                    
        return s.replace(' ','')
        