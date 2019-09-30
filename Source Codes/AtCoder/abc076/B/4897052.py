n = int(input())
k = int(input())
dp = [ [0,0] for i in range(n+1) ]
dp[0][0] = 1
dp[0][1] = 1
for i in range(1,n+1):
    dp[i][0] = min(dp[i-1][0], dp[i-1][1]) * 2
    dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + k
print(min(dp[n][0],dp[n][1]))