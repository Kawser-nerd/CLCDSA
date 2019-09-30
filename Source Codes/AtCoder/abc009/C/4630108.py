#!usr/bin/env python3
from collections import defaultdict
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, input().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return list(sys.stdin.readline())[:-1]
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
mod = 1000000007

#A
"""
n = I()
print(n//2+n%2)
"""

#B
"""
n = I()
a = IR(n)
a = list(set(a))
a.sort()
print(a[-2])
"""

#C
def score(a,d):
    da = defaultdict(int)
    for i in a:
        da[i] += 1
    res = 0
    for i in d.keys():
        res += min(da[i],d[i])
    return len(a)-res
n,k = LI()
s = S()
t = []
l = [1 for i in range(n)]
d = defaultdict(int)
for i in s:
    d[i] += 1
for i in range(n):
    for j in sorted(list(d.keys())):
        if d[j]:
            d[j] -= 1
            sc = score(s[i+1:],d)
            if k >= sc:
                if s[i] == j:
                    t.append(j)
                    break
                elif k > sc:
                    k -= 1
                    t.append(j)
                    break
            d[j] += 1
for i in t:
    print(i,end = "")
print()
#D
"""
def logic_mul_matrix(a,b,n):
    c = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        for j in range(n):
            for l in range(n):
                c[i][j] ^= a[i][l]&b[l][j]
    return c
def logic_pow_matrix(a,l,n):
    if n == 1:
        return a
    if n%2:
        return logic_mul_matrix(a,logic_pow_matrix(logic_mul_matrix(a,a,l),l,n//2),l)
    else:
        return logic_pow_matrix(logic_mul_matrix(a,a,l),l,n//2)

k,m = LI()
a = LI()
c = LI()
if m <= k:
    print(a[m-1])
    quit()
d = pow(2,33)-1
mat = [[d if i == j-1 else 0 for i in range(k)] for j in range(k)]
for i in range(k):
    mat[0][i] = c[i]
mat = logic_pow_matrix(mat,k,m-k)
ans = 0
for i in range(k):
    ans ^= mat[0][i]&a[k-1-i]
print(ans)
"""
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