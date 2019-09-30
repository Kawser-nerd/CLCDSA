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
def A():
    return

#B
def B():
    n,X = LI()
    x = LI()
    for i in range(n-1):
        x[i+1] += x[i]
    x.insert(0,0)
    ans = float("inf")
    f = [5]*(n+1)
    for i in range(1,n):
        f[i+1] = f[i]+2
    for k in range(1,n+1):
        i = 0
        a = n
        d = (k+n)*X
        while a > 0:
            d += f[i]*(x[a]-x[max(0,a-k)])
            a -= k
            i += 1
        ans = min(ans,d)
    print(ans)
#C
def C():
    return

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