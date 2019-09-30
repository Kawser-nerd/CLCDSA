n = int(input())
s = [list(input()) for i in range(n)]
ans = 0
i = 0
while i < n:
    flag = True
    r = n-1
    while s[i][r] == "o":
        r -= 1
        if r < 0:
            flag = False
            break
    if flag:
        ans += 1
        if i == n-1:
            break
        for j in range(r,n):
            s[i+1][j] = "o"
    i += 1
print(ans)