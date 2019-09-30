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
inf = float("INF")

#A
def A():
    return

#B
def B():
    return

#C
def C():
    n = II()
    dp = [inf for i in range(n + 1)]
    ans = [1]
    x = 6
    while x <= n:
        ans.append(x)
        x = x * 6
    x = 9
    while x <= n:
        ans.append(x)
        x = x * 9
    ans.sort()
    for i in ans:
        dp[i] = 1
    for i in range(1, n + 1):
        if not i in ans:
            a = bisect.bisect_left(ans, i)
            for k in range(a):
                #print(i,ans[k], a)
                dp[i] = min(dp[i - ans[k]] + 1, dp[i])
    print(dp[n])

    return

#D
def D():
    n, c = LI()
    D = LIR(c)
    C = LIR_(n)
    CL = list(itertools.permutations(range(c), 3))
    ans = inf
    amari0 = [0 for i in range(30)]
    amari1 = amari0[::1]
    amari2 = amari0[::1]
    for y in range(n):
        for x in range(n):
            amari = (x + y) % 3
            if amari == 0:
                amari0[C[y][x]] += 1
            if amari == 1:
                amari1[C[y][x]] += 1
            if amari == 2:
                amari2[C[y][x]] += 1
    for c0, c1, c2 in CL:
        ansb = 0
        for i in range(c):
            ansb += D[i][c0] * amari0[i]
            ansb += D[i][c1] * amari1[i]
            ansb += D[i][c2] * amari2[i]
        ans = min(ans, ansb)

            
    print(ans)

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