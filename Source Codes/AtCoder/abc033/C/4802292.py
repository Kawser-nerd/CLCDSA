S = input().split('+')
ans = 0
for x in S:
    if not '0' in x:
        ans += 1
print(ans)