N,Ma,Mb=map(int,input().split())

dp = [[10**18 for _ in range(401)] for _ in range(401)]

dp[0][0]=0
for i in range(N):
    a,b,c=map(int,input().split())
    for ca in range(i * 10, -1, -1):
        for cb in range(i * 10, -1, -1):
            dp[ca+a][cb+b] = min(dp[ca+a][cb+b],dp[ca][cb]+c)

ans = 10**18
for ca in range(401):
    for cb in range(401):
        if not ca*Mb == cb*Ma or ca == 0:
            continue
        if ans > dp[ca][cb]:
            ans = dp[ca][cb]
        
if ans == 10**18:
    print(-1)
else:
    print(ans)