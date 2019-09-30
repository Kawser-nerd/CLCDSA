import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 998244353
dd = [(0,-1),(1,0),(0,1),(-1,0)]
ddn = [(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,-1),(-1,0),(-1,1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,m = LI()
    a = [LI_() for _ in range(m)]
    ss = [set() for _ in range(n)]
    for b,c in a:
        ss[b].add(c)
        ss[c].add(b)
    ts = [set(list(range(n))) - set([_]) for _ in range(n)]
    for i in range(n):
        ts[i] -= ss[i]

    d = []
    u = set()
    for i in range(n):
        if i in u:
            continue
        ab = set([i])
        nb = set([i])
        ac = set()
        nc = set()
        f = True
        while f:
            f = False
            k = set()
            nc = set()
            for j in nb:
                nc |= ts[j]
            nc -= ac
            ac |= nc
            nb = set()
            for j in nc:
                nb |= ts[j]
            nb -= ab
            ab |= nb
            if nb:
                f = True
        if ab & ac:
            return -1
        d.append((len(ab),len(ac)))
        u |= ab
        u |= ac
    r = set([0])
    for b,c in d:
        t = set()
        for k in r:
            t.add(k+b)
            t.add(k+c)
        r = t
    rr = inf
    for t in r:
        nt = n - t
        if t == 0 or nt == 0:
            continue
        tr = t * (t-1) // 2
        tr += nt * (nt-1) // 2
        if rr > tr:
            rr = tr
    return rr


print(main())