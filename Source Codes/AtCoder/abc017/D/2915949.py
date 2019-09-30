MOD = 10 ** 9 + 7

n, m = map(int, input().split())
f = [int(input()) for _ in range(n)]

leftmost = 0
last = [0] * m
last[f[0]-1] = 1
dp = [0] * (n + 1)
sums = [0] * (n + 1)
dp[0], dp[1] = 1, 1
sums[0], sums[1] = 1, 2

for i in range(1, n):
	leftmost = max(leftmost, last[f[i]-1])

	if leftmost == 0:
		dp[i+1] = (dp[i] * 2) % MOD
		sums[i+1] = (sums[i] + dp[i+1]) % MOD
		last[f[i]-1] = i+1

	else:
		dp[i+1] = (sums[i] - sums[leftmost - 1]) % MOD
		sums[i+1] = (sums[i] + dp[i+1]) % MOD
		last[f[i]-1] = i+1

#print(dp)
#print(sums)
print(dp[n])