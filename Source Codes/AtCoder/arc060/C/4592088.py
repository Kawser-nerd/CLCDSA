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
    return

#C
def C():
    n = I()
    x = LI()
    l = I()
    k = int(math.log(n,2))
    f = [[i for j in range(k+1)] for i in range(n)]
    for i in range(n-1):
        j = bisect.bisect_left(x,x[i]+l)
        if j < n:
            if x[j] > x[i]+l:
                f[i][0] = j-1
            else:
                f[i][0] = j
        else:
            f[i][0] = j-1
    po2 = [1]*(k+1)
    for i in range(k):
        po2[i+1] = po2[i]*2
    for j in range(k):
        for i in range(n):
            f[i][j+1] = f[f[i][j]][j]
    q = I()
    for i in range(q):
        a,b = LI()
        a,b = [min(a,b)-1, max(a,b)-1]
        ans = 0
        while a < b:
            i = bisect.bisect_left(f[a],b)
            ans += po2[max(0,i-1)]
            a = f[a][max(0,i-1)]
        print(ans)

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
    C()