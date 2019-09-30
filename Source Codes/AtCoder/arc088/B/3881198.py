s = list(input())
s = list(map(int, s))

length = len(s)
i = 0
while i < len(s) - 1:
    if s[i] != s[i+1]:
        length = min(length, max(i+1, len(s) - i - 1))
    i += 1
print(length)