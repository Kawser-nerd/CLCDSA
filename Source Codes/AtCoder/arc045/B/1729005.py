from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
import random
INF = float("inf")


def main():
    N, M = map(int, input().split())
    dp = [0] * (N + 1)
    s_t_list = []
    for _ in range(M):
        s, t = map(int, input().split())
        s -= 1
        t -= 1
        s_t_list.append((s, t))
        dp[s] += 1
        dp[t + 1] -= 1

    for i in range(N):
        dp[i + 1] += dp[i]
        dp[i] = 1 if dp[i] >= 2 else 0

    for i in range(N):
        if dp[i + 1] != 0:
            dp[i + 1] += dp[i]

    ans = []
    for i, (s, t) in enumerate(s_t_list, start=1):
        if dp[t] - dp[s] == t - s and dp[t] != 0 and dp[s] != 0:
            ans.append(i)

    print(len(ans))
    if ans:
        print(*ans, sep="\n")


if __name__ == '__main__':
    main()