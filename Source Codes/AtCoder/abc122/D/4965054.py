MOD = 10**9+7
n = int(input())
A, C, G, T = 0, 1, 2, 3
dp = [[[[1 for _ in range(4)] for _ in range(4)] for _ in range(4)] for _ in range(n+1)]
dp[3][A][G][C] = 0
dp[3][A][C][G] = 0
dp[3][G][A][C] = 0

for i in range(4, n+1):
	for j in range(4):
		for k in range(4):
			for l in range(4):
				dp[i][j][k][l] = 0
				for h in range(4):
					if l == C:
						if h == A and k == G:
							continue
						if h == A and j == G:
							continue
					dp[i][j][k][l] += dp[i-1][h][j][k]

				dp[i][j][k][l] %= MOD

	dp[i][A][G][C] = 0
	dp[i][A][C][G] = 0
	dp[i][G][A][C] = 0

ans = 0
for j in range(4):
	for k in range(4):
		for l in range(4):
			ans += dp[n][j][k][l]
			ans %= MOD
print(ans)