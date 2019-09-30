import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def main():
    n, m, Y, Z = map(int, input().split())
    points = []
    color_no = {}
    for i in range(m):
        c, p = input().split()
        color_no[c] = i
        points.append(int(p))

    b = input()
    block = [0] * n
    for i in range(n):
        block[i] = color_no[b[i]]

    dp = [[[-INF] * 10 for _ in range(2 ** 10)] for j in range(2)]

    for i in range(n):

        color_bit = 1 << block[i]
        dp[(i + 1) & 1][color_bit][block[i]] = points[block[i]]
        for j in range(2 ** m):
            for k in range(m):
                bonus = Y if k == block[i] else 0

                # use
                dp[(i + 1) & 1][j | color_bit][block[i]] = max(dp[(i + 1) & 1][j | color_bit][block[i]],
                                                               dp[i & 1][j][k] + points[block[i]] + bonus)
                # not use
                dp[(i + 1) & 1][j][k] = max(dp[(i + 1) & 1][j][k], dp[i & 1][j][k])

    ans = 0
    for j in range(2 ** m):
        for k in range(m):
            if j + 1 == (1 << m):
                dp[n & 1][j][k] += Z
            ans = max(ans, dp[n & 1][j][k])
    print(ans)


if __name__ == '__main__':
    main()