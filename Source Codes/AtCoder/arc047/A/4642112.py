n,m = map(int,input().split())
s = str(input())
ans = 0
tab = 1
for i in range(n):
    if s[i] == "+":
        tab += 1
        if tab > m:
            ans += 1
            tab = 1
    else:
        tab -= 1
print(ans)