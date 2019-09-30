n,a = map(int,input().split())
x = list(map(int,input().split()))
dp = [[[0]*(sum(x)+1) for i in range(n+1)] for j in range(n+1)]
dp[0][0][0] = 1
for i in range(1,n+1):
        for k in range(i):
                for j in range(sum(x)+1):
                        if dp[i-1][k][j]:
                                dp[i][k+1][j+x[i-1]] += dp[i-1][k][j]
        for k in range(i):
                for j in range(sum(x)+1):
                        if dp[i-1][k][j]:
                                dp[i][k][j] += dp[i-1][k][j]
ans = 0
for i in range(1,n+1):
        for j in range(1,sum(x)+1):
                if j == i*a:
                        ans += dp[n][i][j]
print(ans)