class Solution:
    def reverseVowels(self, s: str) -> str:
        word = list(s)
        vowels = {'a','e','i','o','u','A','E','I','O','U'}
        left, right = 0, len(s)-1
        
        while left<right:
            if word[left] in vowels and word[right] in vowels:
                word[left], word[right] = word[right], word[left]
                left+=1
                right-=1
            elif word[left] not in vowels:
                left+=1
            elif word[right] not in vowels:
                right-=1
        return ''.join(word)