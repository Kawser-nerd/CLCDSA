import sys
from bisect import bisect_left
from itertools import accumulate

N = int(input())
a = sorted(map(int, sys.stdin))
prev = [1]*(N+1)
dp = [0]*(N+1)
mod = 10**9+7

for _ in [0]*3:
    for i, n in enumerate(a):
        j = bisect_left(a, n*2)
        dp[j] += prev[i]

    dp = list(accumulate(dp, lambda x, y: (x+y) % mod))
    prev, dp = dp, [0]*(N+1)

print(sum(prev[:-1]) % mod)