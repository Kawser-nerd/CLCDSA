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

#D
n = I()
out = [[] for i in range(n)]
for i in range(n-1):
    a,b = LI()
    a -= 1
    b -= 1
    out[a].append(b)
    out[b].append(a)
dep = [-1 for i in range(n)]
dep[0] = 0
child = [[] for i in range(n)]
q = [0]
while q:
    x = q.pop(0)
    for y in out[x]:
        if dep[y] == -1:
            dep[y] = dep[x]+1
            child[x].append(y)
            q.append(y)
num = [i for i in range(n)]
l = list(zip(num,child,dep))
l.sort(key = lambda x:-x[2])
f = [1 for i in range(n)]
g = [1 for i in range(n)]
for i in range(n):
    for c in l[i][1]:
        g[l[i][0]] *= f[c]
        g[l[i][0]] %= mod
    for c in l[i][1]:
        f[l[i][0]] *= g[c]
        f[l[i][0]] %= mod
    f[l[i][0]] += g[l[i][0]]
    f[l[i][0]] %= mod
print(f[0])
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