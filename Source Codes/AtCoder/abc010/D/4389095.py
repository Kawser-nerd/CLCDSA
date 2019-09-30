#!usr/bin/env python3
from collections import defaultdict
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return list(sys.stdin.readline())
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
mod = 1000000007

#A
"""
s = input()
print(s+"pp")
"""

#B
"""

n = I()
a = LI()
ans = 0
f = [0,0,1,0,1,2,3,0,1,0]
for i in a:
    ans += f[i]
print(ans)
"""

#C
"""
xs,ys,xg,yg,t,v = LI()
n = I()
l = t*v
ans = "NO"
for i in range(n):
    x,y = LI()
    d = ((x-xs)**2+(y-ys)**2)**(1/2)+((x-xg)**2+(y-yg)**2)**(1/2)
    if d <= l:
        ans = "YES"
print(ans)
"""

#D
def bfs(a,b):
    bfs_map = [-1 for i in range(n+1)]
    q = [a]
    bfs_map[a] = 0
    while q:
        x = q.pop(0)
        for y in out[x]:
            if bfs_map[y] == -1:
                q.append(y)
                bfs_map[y] = bfs_map[x]+1
    if bfs_map[b] == -1:return 0
    d = bfs_map[b]
    path = [b]
    y = b
    while d > 0:
        for x in ent[y]:
            if bfs_map[x] == d-1:
                path.insert(0,x)
                y = x
                d -= 1
                break
    return path

def ford_fulkerson(a,b,c):
    ans = 0
    while 1:
        path = bfs(a,b)
        if not path:break
        for i in range(len(path)-1):
            out[path[i]].remove(path[i+1])
            ent[path[i+1]].remove(path[i])
            if not c[path[i+1]][path[i]]:
                c[path[i+1]][path[i]] = 1
                out[path[i+1]].append(path[i])
                ent[path[i]].append(path[i+1])
        ans += 1
    return ans

n,g,e = LI()
p = LI()
out = [[] for i in range(n+1)]
ent = [[] for i in range(n+1)]
c = [[0 for i in range(n+1)] for j in range(n+1)]
for i in p:
    out[i].append(n)
    c[i][n] = 1
    ent[n].append(i)
for i in range(e):
    a,b = LI()
    out[a].append(b)
    out[b].append(a)
    c[a][b] = 1
    c[b][a] = 1
    ent[a].append(b)
    ent[b].append(a)
print(ford_fulkerson(0,n,c))
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