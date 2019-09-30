#coding: utf-8
s = list(input())
ans = 0
b = 0
for i in range(len(s)):
    if s[i] == "W":
        ans += i - b
        b += 1
print(ans)