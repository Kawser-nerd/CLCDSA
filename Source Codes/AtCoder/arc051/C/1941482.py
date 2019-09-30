import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache, reduce
from operator import xor
from heapq import heappush, heappop
INF = float("inf")
sys.setrecursionlimit(10**7)

# 4????, ?, ?, ??
dy4, dx4 = [0, -1, 0, 1], [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W
def ceil(a, b): return (a + b - 1) // b

MOD = 10 ** 9 + 7


def main():
    N, A, B = map(int, input().split())
    a = list(sorted(list(map(int, input().split()))))

    if A == 1:
        print(*a, sep="\n")
        return

    while B > 0:
        if a[-1] <= a[0] * A:
            break
        a[0] *= A
        a.sort()
        B -= 1

    if B == 0:
        print(*a, sep="\n")
        return

    mul = B // N
    remain = B % N
    for i in range(remain, N):
        print(a[i] * pow(A, mul, MOD) % MOD)

    for i in range(remain):
        print(a[i] * pow(A, mul + 1, MOD) % MOD)


if __name__ == '__main__':
    main()