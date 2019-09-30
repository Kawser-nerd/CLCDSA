from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)
INF = float("inf")
YES, Yes, yes, NO, No, no = "YES", "Yes", "yes", "NO", "No", "no"
dy4, dx4 = [0, 1, 0, -1], [1, 0, -1, 0]
dy8, dx8 = [0, -1, 0, 1, 1, -1, -1, 1], [1, 0, -1, 0, 1, 1, -1, -1]


def inside(y, x, H, W):
    return 0 <= y < H and 0 <= x < W


def ceil(a, b):
    return (a + b - 1) // b


def main():
    N = int(input())
    A, B = [], []

    total = 0
    for _ in range(N):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
        total += a

    r = INF
    for a, b in zip(A, B):
        if a == 0 and b == 0:
            continue
        if b < a:
            r = min(r, b)

    if r == INF:
        print(0)
    else:
        print(total - r)


if __name__ == '__main__':
    main()