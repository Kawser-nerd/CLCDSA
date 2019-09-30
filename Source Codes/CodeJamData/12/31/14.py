#!/usr/bin/python

import sys

sys.setrecursionlimit(10000)

def get(n, graph):
    visited = [False] * n
    order = []

    def dfs(now):
        if visited[now]: return
        visited[now] = True
        for x in graph[now]:
            dfs(x)
        order.append(now)

    for x in xrange(n):
        dfs(x)

    def check(now):
        checked[now] = True
        if visited[now]: return True
        visited[now] = True
        for x in graph[now]:
            if check(x): return True
        return False

    # in topo order
    checked = [False] * n
    for x in reversed(order):
        visited = [False] * n
        if not checked[x] and check(x): return 'Yes'
    return 'No'

t = input()
for x in xrange(t):
    n = input()
    graph = [[] for i in xrange(n)]
    for y in xrange(n):
        nums = map(int, raw_input().strip().split())
        for z in nums[1:]:
            graph[y].append(z-1)
    print 'Case #%d: %s' % (x + 1, get(n, graph))
