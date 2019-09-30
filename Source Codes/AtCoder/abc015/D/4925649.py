W = int(input())
N,K = map(int, input().split())
A = [list(map(int,input().split())) for l in range(N)]
dp = [[10**5 for _ in range(5001)]for _ in range(51)]
dp[0][0] = 0
t = 0
for i in range(N):
    for j in range(i,-1,-1):
        for k in range(t,-1,-1):
            dp[j+1][k+A[i][1]] = min(dp[j][k]+A[i][0],dp[j+1][k+A[i][1]])
    t +=A[i][1]
ans = 0
for i in range(1,K+1):
    for j in range(5001):
        if dp[i][j]<=W:
            ans = max(ans,j)
print(ans)