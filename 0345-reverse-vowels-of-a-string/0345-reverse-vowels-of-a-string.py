class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = []
        for i, char in enumerate(s):
            if char in ['a','e','i','o','u','A','E','I','O','U']:
                vowels.append(char)
                
        for i in range(len(vowels)//2):
            vowels[i],vowels[-i-1]=vowels[-i-1], vowels[i]
        
        word=''
        pointer = 0
        for i in s:
            if i in ['a','e','i','o','u','A','E','I','O','U']:
                word+=vowels[pointer]
                pointer+=1
            else:
                word+=i
        return word