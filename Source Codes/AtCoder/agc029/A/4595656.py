s = input()

ans = 0
b = 0
for ss in s:
    if ss == 'W':
        ans += b
    else:
        b += 1
print(ans)