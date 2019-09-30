import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**15
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,k = LI()
    a = LI_()
    r = 0
    if a[0] != 0:
        r += 1
    e = collections.defaultdict(set)
    for i in range(1,n):
        e[a[i]].add(i)

    def f(i, p):
        m = 0
        r = 0
        for c in e[i]:
            ct,cr = f(c, i)
            r += cr
            if ct > m:
                m = ct
        if (m == k-1 and p != 0) or (m == k and p == 0):
            r += 1
            m = -1
        return (m+1,r)

    for c in e[0]:
        m,t = f(c,0)
        r += t
    return r


print(main())