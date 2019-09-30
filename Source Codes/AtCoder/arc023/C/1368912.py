import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

def inv(a):
    n = mod - 2
    r = 1
    while n > 0:
        if n % 2 == 1:
            r = r * a % mod
        a = a * a % mod
        n >>= 1
    return r

def nCb(n, b):
    if b > n - b:
        b = n - b
    r = 1
    for k in range(n, n-b, -1):
        r = r * k % mod
    d = 1
    for k in range(1, b+1):
        d = d * k % mod
    return r * inv(d) % mod


def main():
    N = I()
    a = LI()
    r = 1
    t = 0
    b = 0
    for c in a:
        if c < 0:
            t += 1
            continue
        if t > 0:
            n = c - b
            m = nCb(n+t,n)
            r *= m
            r %= mod
        b = c
        t = 0
    return r

print(main())