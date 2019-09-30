s = input()

ans = ''
for x in s:
    if x in ['0', '1']:
        ans += x
    else:
        ans = ans[:-1]

print(ans)