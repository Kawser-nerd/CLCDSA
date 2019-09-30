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
out = [0 for i in range(n)]
pow2 = [1]
for i in range(n):
    pow2.append(pow2[-1]*2)
for i in range(m):
    x,y = LI()
    x -= 1
    y -= 1
    out[x] += pow2[y]
k = pow2[n]
dp = [0 for i in range(k)]
dp[0] = 1
bi = [[i,pow2[i]] for i in range(n)]
for i in range(k):
    for j,bij in bi:
        if (not (i & bij))and(not (i & out[j])):
            dp[i | bij] += dp[i]
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