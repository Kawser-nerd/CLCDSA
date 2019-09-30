n,l = map(int,input().split(' '))
s = input()
ans = 0
tab = 1
for i in s:
    if i == '+':
        tab += 1
        if tab > l:
            ans += 1
            tab = 1
    else:
        if tab > 1:
            tab -= 1
print(ans)