#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
agc012 C
"""


n, m = map(int, input().split())

graph = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

q = int(input())
qlist = [tuple(map(int, input().split())) for i in range(q)]
qlist.reverse()

dp = [[-1]*11 for i in range(n+1)]
col = [0]


def updatedp(v, t, d):
    if dp[v][d] == -1:
        for i in range(d+1):
            if dp[v][i] == -1:
                dp[v][i] = t
        if d > 0:
            for u in graph[v]:
                updatedp(u, t, d-1)


t = 0
for v, d, c in qlist:
    col.append(c)
    updatedp(v, t, d)
    t += 1

for i in range(1, n+1):
    print(col[dp[i][0]+1])