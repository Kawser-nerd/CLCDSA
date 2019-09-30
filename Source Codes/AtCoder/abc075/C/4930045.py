import math
import functools
import itertools
import numpy as np
import sys
MAX_INT = int(10e10)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

# Union-Find #
def init(n):
    for i in range(N):
        par[i]=i
        rnk[i]=0
def find(x):
    if par[x]==x:
        return x
    else:
        par[x]=find(par[x])
        return par[x]
def unite(x,y):
    x=find(x)
    y=find(y)
    if x==y:
        return
    if (rnk[x]<rnk[y]):
        par[x]=y
    else:
        par[y]=x
        if(rnk[x]==rnk[y]):
            rnk[x]+=1
def same(x,y):
    return find(x)==find(y)

N,M = IL()
ab = [IL() for i in range(M)]

cnt = 0
for k in range(M):
    par=[0 for i in range(N)]
    rnk=[0 for i in range(N)]
    init(N)
    for i in range(M):
        if k == i:
            continue
        else:
            a,b = ab[i]
            unite(a-1,b-1)
    tmp = find(0)
    for i in range(1,N):
        if tmp == find(i):
            continue
        else:
            cnt += 1
            break
print(cnt)