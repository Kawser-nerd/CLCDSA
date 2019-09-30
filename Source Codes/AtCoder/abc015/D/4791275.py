import numpy as np

W = int(input())
N, K =map(int, input().split())
wid_val = [[int(_) for _ in input().split()] for _ in range(N)]
dp = np.zeros([N+1, W+1, K+1], dtype=int)

for i in range(1, N+1):
    key = wid_val[i-1][0]
    dp[i, :key, :] = dp[i-1, :key, :]
    dp[i, key:, 1:] = np.maximum(dp[i-1, key:, 1:], dp[i-1, :-key, :-1]+wid_val[i-1][1])

print(dp[N][W][K])