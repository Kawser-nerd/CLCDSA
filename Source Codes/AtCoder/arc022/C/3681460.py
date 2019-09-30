# coding:utf-8

import sys
from collections import defaultdict, deque


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


N = int(input())
G = defaultdict(list)
for _ in range(N - 1):
    a, b = inpl()
    G[a - 1].append(b - 1)
    G[b - 1].append(a - 1)


def DFS(start):
    stack = deque([start])
    dist = [INF] * N
    dist[start] = 0
    max_dist = 0
    farthest_v = start
    while stack:
        curr = stack.pop()

        for next in G[curr]:
            if dist[next] != INF:
                continue
            dist[next] = dist[curr] + 1
            stack.append(next)
            if dist[next] > max_dist:
                max_dist = dist[next]
                farthest_v = next

    return farthest_v


v = DFS(0)
u = DFS(v)
print(v + 1, u + 1)