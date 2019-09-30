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
    from datetime import datetime, timedelta
    N = int(input())
    l = []
    for _ in range(N):
        m, d = map(int, input().split("/"))
        l.append((m, d))

    d = datetime(year=2012, month=1, day=1)
    ans = 0
    n, r = 0, 0
    while d.year == 2012:
        if d.weekday() in [5, 6] and (d.month, d.day) in l:
            r += 1
            n += 1
        elif d.weekday() in [5, 6]:
            n += 1
        elif (d.month, d.day) in l:
            n += 1
        else:
            if r == 0:
                n = 0
            else:
                n += 1
                r -= 1
        d += timedelta(days=1)
        ans = max(ans, n)

    print(ans)


if __name__ == '__main__':
    main()