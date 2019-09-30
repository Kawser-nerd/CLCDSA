s = [list(input()) for _ in range(12)]

ans = 0
for i in range(len(s)):
    if s[i].count("r") > 0:
        ans += 1
print(ans)