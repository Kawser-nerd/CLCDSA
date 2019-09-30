n,k = (int(i) for i in input().split())
dp = [[[0,0] for i in range(k+2)] for i in range(n+1)]
for i in range(k+1): dp[n][i][1] = 1
for i in range(n-1,-1,-1):
	for j in range(min(i+1,k+1)):
		dp[i][j][0] = (dp[i+1][j][0]*i+max(dp[i+1][j][0],dp[i+1][j+1][1]))/(i+1)
		dp[i][j][1] = (dp[i+1][j][1]*i+max(dp[i+1][j][0],dp[i+1][j+1][1]))/(i+1)
print(dp[0][0][0])