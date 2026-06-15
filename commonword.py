class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
        for c in "!?',;.": 
            paragraph = paragraph.replace(c, " ")
        d, res, count = {}, "", 0
        for word in paragraph.lower().split():
            if word in banned:
                continue
            if word in d:
                d[word] += 1
            else:
                d[word] = 1
            if d[word] > count:
                count = d[word]
                res = word
                
        return res
