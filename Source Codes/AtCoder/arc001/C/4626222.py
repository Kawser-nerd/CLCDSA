#!usr/bin/env python3
from collections import defaultdict
from heapq import heappush, heappop
import sys
import math
import bisect
import itertools
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
def A():
    n = I()
    c = S()
    minans = float("INF")
    maxans = 0
    for i in range(1,5):
        minans = min(minans, c.count(str(i)))
        maxans = max(maxans, c.count(str(i)))
    print(maxans, minans)

#B
def B():
    a, b = LI()
    ans = 0
    while a != b:
        if a > b:
            a = a ^ b
            b = a ^ b
            a = a ^ b
        ab = b - a
        if ab >= 8:
            a += 10
        elif ab >= 3:
            a += 5
        else:
            a += 1
        ans += 1
    print(ans)
if __name__ == '__main__':
    B()