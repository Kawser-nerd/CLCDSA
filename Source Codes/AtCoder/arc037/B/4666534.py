# -*- coding: utf-8 -*-

def dfs():
    ret = 1
    while stack:
        node, parent = stack.pop()
        visited[node]=1
        for e in edges[node]:
            if(e!=parent and visited[e]==1):
                ret = 0
            elif(e!=parent and visited[e]==0):
                stack.append([e, node])
    return ret
    
if(__name__ == "__main__"):
    N, M = map(int, input().split())
    edges = [set() for i in range(N)]
    visited = [0]*N
    res = 0
    stack = []
    for i in range(M):
        u, v = map(int, input().split())
        u, v = u-1, v-1
        edges[u].add(v)
        edges[v].add(u)

    for i in range(N):
        if(visited[i] == 0):
            stack.append([i, -1])
            res += dfs()
    
    print(res)