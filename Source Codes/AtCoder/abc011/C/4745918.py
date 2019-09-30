N, NG = int(input()), [int(input()) for i in range(3)]
if N in NG: print('NO'); exit()
INF = 10 ** 7
dp = [INF for i in range(N + 1)]
dp[N] = 0
for i in range(N, 0, -1):
    if i not in NG:
        for j in range(1, 4):
            dp[i - j] = min(dp[i] + 1, dp[i - j])
print('YES' if dp[0] <= 100 else 'NO')