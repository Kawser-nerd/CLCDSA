S = input()

ans = 0
now = S[0]
for s in S[1:]:
    if s != now:
        now = s
        ans += 1
print(ans)