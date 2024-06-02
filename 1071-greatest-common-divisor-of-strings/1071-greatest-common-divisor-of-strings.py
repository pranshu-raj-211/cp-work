from difflib import SequenceMatcher

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1+str2 == str2+str1:
            return str1[0:gcd(len(str1), len(str2))]
        return ''    
    def find_gdc(self, a, b):
        if a == 0:
            return b
        return gcd(b%a, a)