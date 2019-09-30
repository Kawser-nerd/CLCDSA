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


color, depth, graph = [], [], {}
def func(v, d, c):
    if not color[v]:
        color[v] = c
    if depth[v] >= d or d == 0:
        return
    depth[v] = d
    for u in graph[v]:
        func(u, d - 1, c)


def main():
    global color, depth, graph
    N, M = map(int, input().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        graph[a].append(b)
        graph[b].append(a)

    Q = int(input())
    q = []
    for _ in range(Q):
        v, d, c = map(int, input().split())
        q.append((v - 1, d, c))

    color = [0] * N
    depth = [0] * N
    for i in range(Q - 1, -1, -1):
        func(q[i][0], q[i][1], q[i][2])
    print(*color, sep="\n")

if __name__ == '__main__':
    main()