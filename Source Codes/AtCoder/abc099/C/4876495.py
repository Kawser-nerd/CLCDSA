L = [1, 6, 36, 216, 1296, 7776, 46656, 9, 81, 729, 6561, 59049]

N = int(input())

dp = [float("inf") for i in range(200000)]
dp[0] = 0
for i in range(N + 1):
	for j in L:
		if dp[i] + 1 <= dp[i + j]:
			dp[i + j] = dp[i] + 1
print(dp[N])