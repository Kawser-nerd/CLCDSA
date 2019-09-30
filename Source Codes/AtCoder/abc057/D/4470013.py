#!usr/bin/env python3
from collections import defaultdict
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

#B

#C
"""
n = I()
ans = int(math.log10(n)+1)
for i in range(2,int(n**0.5)+1):
    if n%i == 0:
        ans = min(ans, max(int(math.log10(i)+1),int(math.log10(n//i)+1)))
print(ans)
"""

#D
n,a,b = LI()
v = LI()
v.sort()
v = v[::-1]
ans = v[:a]
d = {}
d[ans[-1]] = 0
if ans[0] != ans[-1]:
    for i in ans:
        if i == ans[-1]:
            d[i] += 1
    k = d[i]
    d[i] = 0
    for i in v:
        if i == ans[-1]:
            d[i] += 1
    c = 1
    for j in range(min(k,d[ans[-1]]-k)):
        c *= d[ans[-1]]-j
        c //= j+1
else:
    for i in v:
        if i == ans[-1]:
            d[i] += 1
    c = 0
    for k in range(a,min(d[ans[-1]],b)+1):
        p = 1
        for j in range(min(k,d[ans[-1]]-k)):
            p *= d[ans[-1]]-j
            p //= j+1
        c += p
print(sum(ans)/a)
print(c)
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