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


# O((E + V) log V)
def dijkstra(adj, start):
    from heapq import heappop, heappush
    n = len(adj)  # ????????
    dist = [INF for _ in range(n)]

    dist[start] = 0
    q = []
    heappush(q, (0, start))
    while len(q) != 0:
        pre_cost, src = heappop(q)

        if dist[src] < pre_cost:
            continue

        for dest in range(n):
            cost = adj[src][dest]
            if cost != float('inf') and dist[dest] > dist[src] + cost:
                dist[dest] = dist[src] + cost
                heappush(q, (dist[dest], dest))

    return dist


def main():
    N = int(input())
    l = []
    for _ in range(N):
        x, y, t, r = map(int, input().split())
        l.append((x, y, t, r))

    adj = [[INF] * N for _ in range(N)]
    for i, (x1, y1, t1, r1) in enumerate(l):
        for j, (x2, y2, t2, r2) in enumerate(l):
            if i == j:
                adj[i][j] = 0
            else:
                d = sqrt((y2 - y1) ** 2 + (x2 - x1) ** 2)
                adj[i][j] = d / min(t1, r2)

    dist = dijkstra(adj, 0)
    dist[0] = 0
    dist.sort()

    ans = 0
    for i in range(1, len(dist)):
        ans = max(ans, dist[i] + N - i - 1)
    print("{0:.7f}".format(ans))


if __name__ == '__main__':
    main()