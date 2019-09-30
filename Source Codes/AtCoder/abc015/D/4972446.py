import numpy as np

W = int(input())
N, K = map(int, input().split())
wid = [None]
imp = [None]
for _ in range(N):
    a, b = map(int, input().split())
    wid.append(a)
    imp.append(b)
    
# dp[w][n][k]: ??w???????, 0?n?????????k???????????????
dp = np.zeros([W+1, N+1, K+1], dtype=int)

for n in range(1, N+1):
    dp[:wid[n], n, :] = dp[:wid[n], n-1, :]
    dp[wid[n]:, n, 1:] = np.maximum(dp[wid[n]:, n-1, 1:], dp[:-wid[n], n-1, :-1] + imp[n])
print(dp[W, N, K])