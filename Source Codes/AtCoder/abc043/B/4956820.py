s = input()
ans = ''
for c in s:
    if c == 'B':
        ans = ans[:-1]
    else:
        ans += c
print(ans)