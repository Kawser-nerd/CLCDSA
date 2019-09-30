import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    n = I()
    a = LI()
    e = collections.defaultdict(list)
    for _ in range(n-1):
        b,c = LI_()
        e[b].append(c)
        e[c].append(b)

    if n == 2:
        if a[0] == a[1]:
            return 'YES'
        return 'NO'

    def f(c, p):
        t = []
        ac = a[c]
        for d in e[c]:
            if d == p:
                continue
            r = f(d, c)
            if not r and r != 0:
                return
            t.append(r)

        if not t:
            return ac

        ts = sum(t)
        ma = min(ts//2, ts-max(t))
        at = ts - ac
        if at > ma or at < 0 or at > ac:
            return
        return ac - at

    for i in range(n):
        if len(e[i]) == 1:
            continue
        r = f(i,-1)
        if r == 0:
            return 'YES'
        return 'NO'

    return 'NO'




print(main())