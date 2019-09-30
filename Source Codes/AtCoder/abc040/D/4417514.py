#!usr/bin/env python3
from collections import defaultdict
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return list(map(list, sys.stdin.readline().split()))
def S(): return list(sys.stdin.readline())[:-1]
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
mod = 1000000007


#A

#B

#C
"""
def dijkstra():
    d = [float("inf") for i in range(n)]
    d[0] = 0
    q = [[0,0]]
    while q:
        dx,x = heappop(q)
        for y,dy in out[x]:
            if dx+dy < d[y]:
                d[y] = dx+dy
                heappush(q,[d[y],y])
    return d
n = I()
a = LI()
out = [[] for j in range(n)]
for i in range(n-2):
    out[i].append([i+1,abs(a[i+1]-a[i])])
    out[i].append([i+2,abs(a[i+2]-a[i])])
out[n-2].append([n-1,abs(a[n-1]-a[n-2])])
d = dijkstra()
print(d[n-1])
"""

#D
def root(x):
    if x == par[x]:
        return x
    par[x] = root(par[x])
    return par[x]

def unite(x,y):
    x = root(x)
    y = root(y)
    if x == y:return
    if rank[x] < rank[y]:
        par[x] = y
        size[y] += size[x]
    else:
        par[y] = x
        size[x] += size[y]
        if rank[x] == rank[y]:
            rank[x] += 1

n,m = LI()
v = []
for i in range(m):
    x,y,w = LI()
    v.append([x-1,y-1,w])
v.sort(key = lambda x:-x[2])
Q = I()
q = [[LI(),i] for i in range(Q)]
q.sort(key = lambda x:-x[0][1])
par = [i for i in range(n)]
rank = [0 for i in range(n)]
size = [1 for i in range(n)]
ans = []
j = 0
for p,i in q:
    while j < m and v[j][2] > p[1]:
        x,y,w = v[j]
        unite(x,y)
        j += 1
    ans.append([size[root(p[0]-1)],i])
ans.sort(key = lambda x:x[1])
for i,j in ans:
    print(i)
#E

#F

#G

#H

#I

#J

#K

#L

#M

#N

#O

#P

#Q

#R

#S

#T