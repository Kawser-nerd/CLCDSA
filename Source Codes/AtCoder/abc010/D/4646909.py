#!usr/bin/env python3
from collections import defaultdict
from collections import deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS():return list(map(list, sys.stdin.readline().split()))
def S(): return list(sys.stdin.readline())[:-1]
def IR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = I()
    return l
def LIR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = LI()
    return l
def SR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = S()
    return l
def LSR(n):
    l = [None for i in range(n)]
    for i in range(n):l[i] = SR()
    return l
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
def bfs(s,g):
    bfs_map = [-1 for i in range(n+1)]
    bfs_map[s] = 0
    q = deque()
    q.append(s)
    fin = False
    while q:
        x = q.popleft()
        for y in range(n+1):
            if c[x][y] > 0 and bfs_map[y] < 0:
                bfs_map[y] = bfs_map[x]+1
                if y == g:
                    fin = True
                    break
                q.append(y)
        if fin:
            break

    if bfs_map[g] == -1:
        return [None,0]
    path = [None for i in range(bfs_map[g]+1)]
    m = float("inf")
    path[bfs_map[g]] = g
    y = g
    for i in range(bfs_map[g])[::-1]:
        for x in range(n+1):
            if c[x][y] > 0 and bfs_map[x] == bfs_map[y]-1:
                path[i] = x
                if c[x][y] < m:
                    m = c[x][y]
                y = x
                break
    return [path,m]

def ford_fulkerson(s,g,c):
    while 1:
        p,m = bfs(s,g)
        if not m:break
        for i in range(len(p)-1):
            c[p[i]][p[i+1]] -= m
            c[p[i+1]][p[i]] += m

    return sum(c[n])

n,g,e = LI()
p = LI()
c = [[0 for i in range(n+1)] for j in range(n+1)]
for i in p:
    c[i][n] = 1
for i in range(e):
    a,b = LI()
    c[a][b] = 1
    c[b][a] = 1
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