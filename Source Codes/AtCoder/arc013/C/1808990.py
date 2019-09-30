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
    N = int(input())
    ans = 0
    for _ in range(N):
        X, Y, Z = map(int, input().split())
        M = int(input())
        a, b, c, d, e, f = X, X, Y, Y, Z, Z
        for _ in range(M):
            x, y, z = map(int, input().split())
            a, b = min(a, x), min(b, X - x - 1)
            c, d = min(c, y), min(d, Y - y - 1)
            e, f = min(e, z), min(f, Z - z - 1)
        ans ^= (a ^ b ^ c ^ d ^ e ^ f)

    print("WIN" if ans != 0 else "LOSE")




if __name__ == '__main__':
    main()