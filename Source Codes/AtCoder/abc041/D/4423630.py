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
n = I()
a = LI()
for i in range(n):
    a[i] = [a[i],i+1]
a.sort(key = lambda x:-x[0])
for i in a:
    print(i[1])
"""

#D
n,m = LI()
out = [[] for i in range(n)]
for i in range(m):
    x,y = LI()
    x -= 1
    y -= 1
    out[x].append(y)
k = pow(2,n)
dp = [0 for i in range(k)]
dp[0] = 1
l = [[list(map(int,bin(i)[2:])),i] for i in range(k)]
for i in range(k):
    for j in range(n-len(l[i][0])):
        l[i][0].insert(0,0)
    l[i] += [sum(l[i][0])]
l.sort(key = lambda x:x[2])
pow2 = [pow(2,i) for i in range(n)]
l.pop(0)
for s,i,num in l:
    d = i
    p = 0
    for p in range(n):
        if d%2:
            f = True
            for q in out[p]:
                if s[-1-q]:f = False
            if f:
                dp[i] += dp[i-pow2[p]]
        d //= 2
print(dp[-1])
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