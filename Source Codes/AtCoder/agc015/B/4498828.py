s = input()
ls = len(s)
ans = 0
for i in range(1,ls+1):
    if s[i-1] == 'U':
        ans += ls-i + (i-1)*2
    else:
        ans += (ls-i)*2 + i-1
print(ans)