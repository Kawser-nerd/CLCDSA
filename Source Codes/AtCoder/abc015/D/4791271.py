import numpy as np
from itertools import product

W = int(input())
N, K =map(int, input().split())
wid_val = [[int(_) for _ in input().split()] for _ in range(N)]
dp = np.zeros([N+1, W+1, K+1], dtype=int)

for i, num in product(range(1, N+1), range(1, K+1)):
    key = wid_val[i-1][0]
    dp[i, :key, num] = dp[i-1, :key, num]
    dp[i, key:, num] = np.maximum(dp[i-1, key:, num], dp[i-1, :-key, num-1]+wid_val[i-1][1])

print(dp[N][W][K])