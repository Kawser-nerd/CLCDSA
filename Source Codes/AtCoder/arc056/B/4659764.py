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
sys.setrecursionlimit(1000000)

#A
def A():
    return

#B
def B():
    def root(x):
        if x == par[x]:
            return x
        par[x] = root(par[x])
        return par[x]
    def same(x,y):
        return root(x) == root(y)
    def unite(x,y):
        x = root(x)
        y = root(y)
        if rank[x] < rank[y]:
            par[x] = y
        else:
            par[y] = x
            if rank[x] == rank[y]:
                rank[x] += 1
    n,m,s = LI()
    s -= 1
    v = [None for i in range(m)]
    for i in range(m):
        x,y = LI()
        x,y = max(x,y)-1,min(x,y)-1
        v[i] = [[x,y],y]
    v.sort(key = lambda x:-x[1])
    par = [i for i in range(n)]
    rank = [0 for i in range(n)]
    f = [0 for i in range(n)]
    j = 0
    for i in range(n)[::-1]:
        while j < m:
            if v[j][1] < i:break
            x,y = v[j][0]
            if not same(x,y):
                unite(x,y)
            j += 1
        if same(s,i):
            f[i] = 1
    for i in range(n):
        if f[i]:
            print(i+1)

#C
def C():
    def root(x):
        if x == par[x]:
            return x
        par[x] = root(par[x])
        return par[x]
    def same(x,y):
        return root(x) == root(y)
    def unite(x,y):
        x = root(x)
        y = root(y)
        if rank[x] < rank[y]:
            par[x] = y
        else:
            par[y] = x
            if rank[x] == rank[y]:
                rank[x] += 1
    n,k = LI()
    w = LIR(n)
    ans = -float("inf")
    v = []
    for i in range(n):
        for j in range(i):
            v.append([w[i][j],i,j])
    v.sort(key = lambda x:-x[0])
    g = n
    par = [i for i in range(n)]
    rank = [0 for i in range(n)]
    for i in range(1,n+1)[::-1]:
        m = i*k
        while g > i:
            c,x,y = v.pop(0)
            if not same(x,y):
                unite(x,y)
                g-=1
        for i in range(n):
            for j in range(i):
                if not same(i,j):
                    m -= w[i][j]
        print(g,m)
        ans = max(ans,m)
    print(ans)

#D
def D():
    return

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
    B()