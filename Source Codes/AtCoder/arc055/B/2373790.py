# seishin.py
N, K = map(int, input().split())

dp = [[[0]*2 for i in range(K+2)] for i in range(N+1)]

for j in range(K+1):
    dp[N][j][1] = 1.

for i in range(N-1, -1, -1):
    for j in range(min(K+1, i+1)):
        for b in range(2):
            dp[i][j][b] = (max(dp[i+1][j][0], dp[i+1][j+1][1]) + dp[i+1][j][b]*i)/(i+1)
print(dp[0][0][0])