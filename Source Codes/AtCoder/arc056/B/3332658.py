#!/usr/bin/env python3

import heapq

def main():
    n, m, s1 = map(int, input().split())
    adjs = [set() for i in range(n)]
    for j in range(m):
        u1, v1 = map(int, input().split())
        adjs[u1 - 1].add(v1)
        adjs[v1 - 1].add(u1)

    costs = [None for i in range(n)]
    visited = [False for i in range(n)]
    c = 999999999
    next = [-s1]
    while len(next) > 0:
        x1 = -heapq.heappop(next)
        c = min(c, x1)
        costs[x1 - 1] = c
        for a in adjs[x1 - 1]:
            if not visited[a - 1]:
                heapq.heappush(next, -a)
                visited[a - 1] = True
        visited[x1 - 1] = True
    for x1 in range(1, n + 1):
        if costs[x1 - 1] == x1:
            print(x1)

main()