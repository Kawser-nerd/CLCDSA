import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
INF = float("inf")
sys.setrecursionlimit(10**7)

MOD = 1777777777

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


# O(r)
def nCr(n, r, mod):
    a, b = 1, 1
    for i in range(r):
        a = (a * (n - i)) % mod
        b = (b * (i + 1)) % mod

    return (a * pow(b, mod - 2, mod)) % mod

# ??????
def montmort_number(n, mod):
    assert n > 1
    dp = [None] * (n + 10)
    dp[2] = 1
    dp[3] = 2
    for i in range(4, n + 1):
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % mod
    return dp[n]


def main():
    N, K = map(int, input().split())

    a = nCr(N, K, MOD)
    b = montmort_number(K, MOD)
    print((a * b) % MOD)


if __name__ == '__main__':
    main()