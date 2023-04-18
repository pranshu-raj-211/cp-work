class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        word = ""
        if len(word1) > len(word2):
            for i in range(len(word2)):
                word += word1[i] + word2[i]
            word += word1[i + 1 :]
        else:
            for i in range(len(word1)):
                word += word1[i] + word2[i]
            word += word2[i + 1 :]
        return word
