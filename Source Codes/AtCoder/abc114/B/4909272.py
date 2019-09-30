s = input()

ans = int(s)
for i in range(len(s)):
    gap = abs(int(s[i:i+3])-753)
    if ans >= gap:
        ans = gap
print(ans)