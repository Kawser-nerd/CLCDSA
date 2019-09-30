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
n,m = LI()
x,y = LI()
a = LI()
b = LI()
d = 0
for i in range(n+m):
    if a[-1] < d:
        print(i)
        quit()
    k = bisect.bisect_left(a,d)
    d = a[k]+x
    if b[-1] < d:
        print(i)
        quit()
    k = bisect.bisect_left(b,d)
    d = b[k]+y
"""

#D
"""
n,a = LI()
k = I()
b = LI()
b.insert(0,0)
l = []
d = a
q = defaultdict(int)
while not q[d]:
    q[d] = 1
    l.append(d)
    d = b[d]
    k -= 1
    if k == 0:print(d);quit()
l = l[l.index(d):]
print(l[k%len(l)])
"""

#E
def dfs(v,w,d,d2):
    if len(v) == 0:
        if len(w) == 0:
            for i in range(k):
                for j in range(len(d[i+1])-1):
                    print(d[i+1][j],end = "")
                print(d[i+1][-1])
            quit()
    elif d2[v[0]]:
        if d[v[0]] == w[:d2[v[0]]]:
            dfs(v[1:],w[d2[v[0]]:],d,d2)
    else:
        for i in range(1,4):
            dfs(v[1:],w[i:],d[:v[0]] + [w[:i]] + d[v[0]+1:],d2[:v[0]] + [i] + d2[v[0]+1:])
k,n = LI()
v = []
w = []
d = [[] for i in range(k+1)]
d2 = [0 for i in range(k+1)]
for i in range(n):
    x,y = LS()
    if len(x) == 1:
        d[int(x[0])] = y
        d2[int(x[0])] = len(y)
    else:
        v += list(map(int, x))
        w += y

dfs(v,w,d,d2)
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