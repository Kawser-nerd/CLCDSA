s = input()
pos = 0
ans = 0
for i in range(len(s)):
    if s[i]=="W":
        ans += i-pos
        pos += 1
print(ans)