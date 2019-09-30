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
x = input()
d = {"A":1,"B":2,"C":3,"D":4,"E":5}
print(d[x])
"""

#B
"""
a = I()
b = I()
print(min(abs(b-a),a+10-b,b+10-a))
"""

#C
"""
n,h = LI()
a,b,c,d,e = LI()
ans = float("inf")
for i in range(n+1):
    l = a*i
    j = max(0,math.ceil(((n-i)*e-h-b*i+0.0001)/(d+e)))
    l += c*j
    ans = min(ans,l)
print(ans)
"""

#D
def mul(a,b):
    c = [0 for i in range(n+1)]
    for i in range(n+1):
        c[i] = a[b[i]]
    return c

def pow(a,b):
    if b == 1:
        return a
    if b%2:
        return mul(a,pow(mul(a,a),b//2))
    else:
        return pow(mul(a,a),b//2)
        
n,m,d = LI()
a = LI()
f = [i for i in range(n+1)]
for i in range(m)[::-1]:
    v = f[a[i]]
    f[a[i]] = f[a[i]+1]
    f[a[i]+1] = v
f = pow(f,d)
for i in range(1,n+1):
    print(f[i])
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