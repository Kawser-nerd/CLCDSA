import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, atan, cos, asin
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
    A, B = map(int, input().split())
    A, B = min(A, B), max(A, B)
    r = sqrt(A ** 2 + B ** 2)
    p = atan(A / B)

    N = int(input())
    for _ in range(N):
        C, D = map(int, input().split())
        C, D = min(C, D), max(C, D)

        if C >= A and D >= B:
            print("YES")
        elif (D < B and C < A) or r < D:
            print("NO")
        elif C >= r * cos(asin(D / r) - 2 * p):
            print("YES")
        else:
            print("NO")


if __name__ == '__main__':
    main()