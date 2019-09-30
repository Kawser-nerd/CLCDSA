# -*- coding: utf-8 -*-
from collections import deque
n,m = map(int, input().split())
edge = {}
for _ in range(m):
    l,r,d = map(int,input().split())
    if l not in edge:
        edge[l] = []
    edge[l].append([r,d])
    if r not in edge:
        edge[r] = []
    edge[r].append([l,-1*d])
# print(edge)
x = [None for _ in range(n+1)]

for i in range(1,n+1):
    if x[i] is None:
        x[i] = 0
        q = deque([i])
        while len(q)>0:
            v = q.popleft()
            if v not in edge:
                break
            for u,d in edge[v]:
                # print(v,u,d,x)
                if x[u] is None:
                    x[u] = x[v]+d
                    q.append(u)
                elif x[u]!=x[v]+d:
                    print("No")
                    exit()
        # print(x)

print("Yes")