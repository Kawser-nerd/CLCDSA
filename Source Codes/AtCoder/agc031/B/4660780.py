import sys
input = sys.stdin.readline

N = int(input())
c = []
for _ in range(N):
    c.append(int(input()))

dp = [0] * N
dp[0] = 1
dpc = [0] * (max(c) + 1)
dpc[c[0]] = 1

for i in range(1, N):
    dp[i] = dp[i - 1]
    if c[i] != c[i - 1]:
        dp[i] += dpc[c[i]]
        dpc[c[i]] += dp[i - 1]

print(dp[N - 1] % (10**9+7))