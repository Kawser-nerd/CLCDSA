import sys
from collections import defaultdict, Counter
from itertools import product, groupby, count, permutations, combinations
from math import pi, sqrt
from collections import deque
from bisect import bisect, bisect_left, bisect_right
from heapq import heappush, heappop
INF = float("inf")
sys.setrecursionlimit(10 ** 5)


def main():
    N, M, S = map(int, input().split())
    S -= 1
    graph = defaultdict(list)
    for _ in range(M):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        graph[u].append(v)
        graph[v].append(u)

    h = []
    heappush(h, (-S, S))
    table = [0] * N
    table[S] = S
    while len(h):
        cost, node = heappop(h)
        cost = -cost

        for to in graph[node]:
            new_cost = min(cost, to)
            if new_cost <= table[to]:
                continue
            table[to] = new_cost
            heappush(h, (-new_cost, to))

    for i in range(N):
        if table[i] >= i:
            print(i + 1)

if __name__ == '__main__':
    main()