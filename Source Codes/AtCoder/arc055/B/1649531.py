from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
INF = float("inf")


def main():
    N, K = map(int, input().split())
    dp = [[[0, 0] for j in range(K + 2)] for l in range(N + 1)]
    for j in range(K + 1):
        dp[N][j][1] = 1

    for i in range(N - 1, -1, -1):
        for j in range(K + 1):
            p = 1 / (i + 1)
            a = p * max(dp[i + 1][j + 1][1], dp[i + 1][j][0])
            dp[i][j][1] = (1 - p) * dp[i + 1][j][1] + a
            dp[i][j][0] = (1 - p) * dp[i + 1][j][0] + a

    print(dp[0][0][0])

if __name__ == '__main__':
    main()