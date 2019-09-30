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
"""
s = S()
n = I()
l = []
for i in s:
    for j in s:
        l.append(i+j)
l = list(set(l))
l.sort()
print(l[n-1])
"""

#B
"""
n,a,b = LI()
dict = {"East":0,"West":0}
for i in range(n):
    s,d = LS()
    d = int(d)
    if d < a:
        dict[s] += a
    elif d <= b:
        dict[s] += d
    else:
        dict[s] += b
ans = dict["East"]-dict["West"]
if ans == 0:
    print(0)
elif ans > 0:
    print("East",ans)
else:
    print("West",-ans)
"""
#C
def dfs(d,n):
    if f[n] != None:
        return f[n]
    if d == 9:
        k = [None for i in range(9)]
        m = n
        for i in range(9)[::-1]:
            k[i] = m%3
            m //= 3
        res = 0
        for y in range(2):
            for x in range(3):
                if k[y*3+x] == k[(y+1)*3+x]:
                    res += b[y][x]
        for y in range(3):
            for x in range(2):
                if k[y*3+x] == k[y*3+x+1]:
                    res += c[y][x]
        f[n] = res
        return f[n]
    if d%2:#min
        k = []
        m = n
        for i in range(9):
            if not m%3:k.append(p[i])
            m //= 3
        f[n] = float("inf")
        for i in k:
            f[n] = min(f[n],dfs(d+1,n+2*i))
        return f[n]
    else:
        k = []
        m = n
        for i in range(9):
            if not m%3:k.append(p[i])
            m //= 3
        f[n] = 0
        for i in k:
            f[n] = max(f[n],dfs(d+1,n+i))
        return f[n]

b = LIR(2)
c = LIR(3)
s = sum(b[0])+sum(b[1])+sum(c[0])+sum(c[1])+sum(c[2])
p = [1 for i in range(11)]
for i in range(10):
    p[i+1] = 3*p[i]
f = [None for i in range(p[10])]
dfs(0,0)
print(f[0])
print(s-f[0])
#D

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