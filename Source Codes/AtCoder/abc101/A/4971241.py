S = input()

ans = 0
for c in S:
    if c == '+':
        ans += 1
    else:
        ans -= 1
print(ans)