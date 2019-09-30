S = input()
b = 0
ans = 0
for c in S:
    if c == 'B':
        b += 1
    else:
        ans += b
print(ans)