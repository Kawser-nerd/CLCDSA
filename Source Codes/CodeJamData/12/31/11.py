#!/usr/bin/env python
import sys
sys.setrecursionlimit(1000000)

def dfs(graph, visited, i):
    visited[i] = True
    for v in graph[i]:
        if visited[v]:
            return True
        elif dfs(graph, visited, v):
            return True
    return False

t = int(input())
for case in range(1,t+1):
    n = int(input())
    graph = [list(map(lambda x:int(x)-1,(input().strip().split())[1:])) for _ in range(n)]
    found = False
    for i in range(n):
        visited = [False for _ in range(n)]
        if not visited[i]:
            if dfs(graph, visited, i):
                found = True
                break
    print('Case #{}: {}'.format(case, 'Yes' if found else 'No'))
