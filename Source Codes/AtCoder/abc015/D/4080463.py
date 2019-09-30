W = int(input())
N,K = map(int,input().split())
AB = [tuple(map(int,input().split())) for _ in range(N)]

# dp[i][j] : ????i???????????????j???????
dp = [[1000*N+1+W for _ in range(100*N+1)] for _ in range(N+1)]
dp[0][0] = 0

total = 0
for i in range(N):
    a,b = AB[i]
    for j in range(i,-1,-1):
        for v in range(total,-1,-1):
            dp[j+1][v+b] = min(dp[j+1][v+b], dp[j][v]+a)
    total += b

ans = 0
for i in range(1,K+1):
    for j in range(100*N+1):
        if dp[i][j] <= W:
            ans = max(ans, j)

print(ans)