import math
xs,ys,xg,yg= map(int,input().split())
n = int(input())
c = [[-1,xs,ys,0]]
for i in range(n):
    x,y,r = map(int,input().split())
    c.append([max(math.sqrt(abs(xs-x)**2+abs(ys-y)**2)-r,0),x,y,r])
dp  = [float("inf")]*(n+1)
dp[0] = 0
used = [0]*(n+1)
for i in range(n+1):
    a = float("inf");b=-1
    for j in range(n+1):
        if used[j]:continue
        if a > dp[j]:
            a = dp[j];b = j
    used[b] = 1
    g = b
    _,x,y,r = c[b]
    for j in range(n+1):
        if used[j]:
            continue
        _,x2,y2,r2 = c[j]
        ima = dp[g]+max(0,math.sqrt(abs(x2-x)**2+abs(y2-y)**2)-r-r2)
        if ima < dp[j]:
            dp[j] = ima
ans = float("inf")
for i in range(n+1):
    _,x,y,r = c[i]
    ans = min(dp[i]+max(0,math.sqrt(abs(xg-x)**2+abs(yg-y)**2)-r),ans)
print(ans)