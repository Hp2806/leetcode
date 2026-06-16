s = "HelloWorld"

freq = {}
for ch in s:
    if ch.isalpha():
        freq[ch] = freq.get(ch, 0) + 1

mx = max(freq.values())

for ch in sorted(freq):
    if freq[ch] == mx:
        print(ch, end=" ")
