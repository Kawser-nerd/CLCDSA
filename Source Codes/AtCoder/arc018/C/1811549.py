import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache, reduce
from operator import xor
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def main():
    N, M = map(int, input().split())
    x0, a, p = map(int, input().split())
    students = [(x0, 0, 0)]
    for i in range(1, N * M):
        students.append(((students[-1][0] + a) % p, i // M, i % M))
    students.sort()

    ans = 0
    for i in range(0, N * M, M):
        xs = []
        for j in range(M):
            score, y, x = students[i + j]
            ans += abs(y - ((i + j) // M))
            xs.append(x)
        for j, x in enumerate(sorted(xs)):
            ans += abs(x - j)

    print(ans)


if __name__ == '__main__':
    main()