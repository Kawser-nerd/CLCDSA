from collections import defaultdict
N, W = map(int, input().split())
dp = defaultdict(int)
dp[0] = 0
for _ in range(N):
    w, v = map(int, input().split())
    for pw, pv in dp.copy().items():
        if pw + w <= W:
            dp[pw + w] = max(dp[pw + w], pv + v)

print(max(dp.values()))