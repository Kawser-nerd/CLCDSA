N = int(input())

dp = [0] * (N+1)

for i in range(1, N+1):
    dp[i] = dp[i-1] + 1
    for j in [6, 9]:
        now = j
        while now <= i:
            if i - now >= 0:
                dp[i] = min(dp[i-now] + 1, dp[i])
            now *= j
print(dp[-1])