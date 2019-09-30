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
    for i in range(n):l[i] = LS()
    return l
sys.setrecursionlimit(1000000)
mod = 1000000007

#A
def A():
    return

#B
def B():
    return

#C
def C():
    return

#D
def D():
    def factorize(n):
        if n < 4:
            return [n]
        l = []
        m = n
        i = 2
        while i ** 2 <= m:
            if m%i == 0:
                l.append(i)
                while m%i == 0:
                    m //= i
            i += 1
        if m != 1:
            l.append(m)
        return l

    def divisor(n):
        if n == 1:
            return [1]
        if n < 4:
            return [1,n]
        l = [1]
        m = n
        i = 2
        while i ** 2 <= m:
            if m%i == 0:
                l.append(i)
                if m//i != i:
                    l.append(m//i)
            i += 1
        l.append(n)
        return l
    def dfs(k,n,d):
        if n == len(p):
            pl.append([k,d%2])
        else:
            dfs(k,n+1,d)
            dfs(k*p[n],n+1,d+1)
    def s(n,a):
        res = (n*(n+1))*inv_2%mod
        for b,d in pl[1:]:
            if d:
                res -= b*(n//b*(n//b+1))*inv_2%mod
                res %= mod
            else:
                res += b*(n//b*(n//b+1))*inv_2%mod
                res %= mod
        return res*k%mod
    inv_2 = 500000004
    n,k = LI()
    ans = 0
    l = divisor(k)
    for i in l:
        a = k//i
        if a == 1:
            ans += k*(n//i*(n//i+1))*inv_2%mod
        else:
            p = factorize(a)
            pl = []
            dfs(1,0,0)
            ans += s(n//i,a)
        ans %= mod
    print(ans)
    return

#Solve
if __name__ == "__main__":
    D()