# coding: utf-8
import bisect as bis

# 1 <= n <= 3x10^4
n = int(input())
dp = [-1]
for i in range(n):
    c = int(input())
    if dp[-1] < c:
        dp.append(c)
    else:
        dp[bis.bisect_left(dp, c)] = c

print(n - len(dp) + 1)