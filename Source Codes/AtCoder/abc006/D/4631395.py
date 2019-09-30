#!usr/bin/env python3
from collections import defaultdict
from collections import deque
from heapq import heappush, heappop
import sys
import math
import bisect
import random
import itertools
sys.setrecursionlimit(10**5)
stdin = sys.stdin
inf = float("INF")
def LI(): return list(map(int, stdin.readline().split()))
def LF(): return list(map(float, stdin.readline().split()))
def LI_(): return list(map(lambda x: int(x)-1, stdin.readline().split()))
def II(): return int(stdin.readline())
def IF(): return float(stdin.readline())
def LS(): return list(map(list, stdin.readline().split()))
def S(): return list(stdin.readline().rstrip())
def IR(n): return [II() for _ in range(n)]
def LIR(n): return [LI() for _ in range(n)]
def FR(n): return [IF() for _ in range(n)]
def LFR(n): return [LI() for _ in range(n)]
def LIR_(n): return [LI_() for _ in range(n)]
def SR(n): return [S() for _ in range(n)]
def LSR(n): return [LS() for _ in range(n)]
mod = 1000000007

#A
def A():
    return

#B
def B():
    return

#C
def C():
    n, m = LI()
    a = m % 2
    for y in range(a, n, 2):
        bm = m
        bm -= 3 * y
        bm //= 2
        z = bm - (n - y)
        x = n - y - z
        if z >= 0 and x >= 0 and y >= 0:
            print(x,y,z)
            return
    print(-1,-1,-1)
    return

#D
def D():
    n = II()
    ans = 0
    c = IR(n)
    dp = [inf for i in range(n+1)]
    dp[0] = -1*inf
    for i in c:
        a = bisect.bisect_left(dp, i)
        dp[a] = i
    a = dp.count(inf)
    print(n-len(dp)+1+a)
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
if __name__ == '__main__':
    D()