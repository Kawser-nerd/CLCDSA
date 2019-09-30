import sys

ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nms = lambda: map(str, sys.stdin.readline().split())
nl = lambda: list(nm())

n, m = nm()
a = nl()
lis = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
dp = [-1 for _ in range(n + 1)]
dp[0] = 0
for i in range(1, n + 1):
    for j in a:
        if i - lis[j] >= 0:
            dp[i] = max(dp[i], dp[i - lis[j]] * 10 + j)
print(dp[n])