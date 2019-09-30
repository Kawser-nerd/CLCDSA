import bisect 
import numpy as np
import sys

if __name__ == '__main__':
	n, k = list(map(int, input().split()))
	games = [int(input()) for _ in range(n)]

	if sum(games) == k:
		print(1)
		sys.exit()

	#dp = np.concatenate((np.array([0, 1], dtype = 'int64'), np.full(n - 1, 2000 * 500000 * 	2, dtype = 'int64')))
	dp = [2000 * 500000 * 2 for _ in range(n+1)]
	dp[0] = 0
	dp[1] = 1
	cnt = games[0]

	for i in range(1, n):
		#min_wins = np.array([2000 * 500000 * 2 if x > games[i] else x for x in [(x * games[i]) // cnt + 1 for x in dp[0:(i + 1)]]])
		#dp[1:(i + 2)] = np.minimum(dp[1:(i + 2)], dp[0:(i + 1)] + min_wins)
		#print(dp)
		for i2 in range(i+1, 0, -1):

			if dp[i2] >= 2000 * 500000 * 2 - 1:
				continue
			else:
				dp[i2+1] = min(dp[i2 + 1], dp[i2] + (dp[i2] * games[i]) // cnt + 1)

		cnt += games[i]

	print(max([i for i in range(len(dp)) if dp[i] <= k]))