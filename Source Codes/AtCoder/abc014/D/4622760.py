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
def A():
    return

#B
def B():
    return

#C
def C():
    return

#D
def D():
    n = I()
    v = [[] for i in range(n)]
    for i in range(n-1):
        x,y = LI()
        x -= 1
        y -= 1
        v[x].append(y)
        v[y].append(x)
    lo2 = [0]*n
    k = int(math.log(n,2))+1
    for i in range(k):
        p = 2**i
        for j in range(p):
            if p+j >= n:break
            lo2[p+j] = i
    d = [-1 for i in range(n)]
    par = [[None for j in range(k)] for i in range(n)]
    d[0] = 0
    par[0][0] = 0
    q = deque()
    q.append(0)
    while q:
        x = q.pop()
        for y in v[x]:
            if d[y] < 0:
                d[y] = d[x]+1
                par[y][0] = x
                q.append(y)
    for j in range(k-1):
        for i in range(n):
            par[i][j+1] = par[par[i][j]][j]
    Q = I()
    for q in range(Q):
        x,y = LI()
        x -= 1
        y -= 1
        ans = d[x]+d[y]+1
        while d[x] < d[y]:
            l = d[y]-d[x]
            i = lo2[l]
            y = par[y][i]
        while d[x] > d[y]:
            l = d[x]-d[y]
            i = lo2[l]
            x = par[x][i]
        if x == y:
            lca = x
        else:
            while par[x][0] != par[y][0]:
                l = 0
                r = k
                while r-l > 1:
                    m = (l+r)//2
                    if par[x][m] != par[y][m]:
                        l = m
                    else:
                        r = m
                x = par[x][l]
                y = par[y][l]
            lca = par[x][0]
        ans -= 2*d[lca]
        print(ans)

#E
def E():
    return

#F
def F():
    return

#G
def G():
    return

#H
def H():
    return

#Solve
if __name__ == "__main__":
    D()