import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt, ceil, floor
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from string import ascii_lowercase
from functools import lru_cache, reduce

INF = float("inf")
sys.setrecursionlimit(10 ** 7)

# 4????, ?, ?, ??
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]


def inside(y: int, x: int, H: int, W: int) -> bool: return 0 <= y < H and 0 <= x < W


def dfs(n, p, grundy, graph):
    g = 0
    for x in graph[n]:
        if x != p:
            g ^= dfs(x, n, grundy, graph) + 1
    grundy[n] = g
    return g


def solve(N, graph):
    grundy = [None] * (N + 1)
    dfs(1, 0, grundy, graph)
    return grundy[1] != 0


def main():
    N = int(input())
    graph = defaultdict(list)
    for _ in range(N - 1):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    print("Alice" if solve(N, graph) else "Bob")


if __name__ == '__main__':
    main()