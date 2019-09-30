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
    n,s = LI()
    a = [LI() for _ in range(n)]
    x = [_[0] for _ in a]
    p = [_[1] for _ in a]
    if x[0] > s:
        return x[-1] - s
    if x[-1] < s:
        return s - x[0]
    r = 0
    i = 0
    j = n - 1
    d = p[:]
    e = collections.defaultdict(list)
    sk = set()
    while i < j:
        if x[i] > s:
            break
        if x[j] < s:
            break
        if d[i] >= d[j]:
            d[i] += d[j]
            j -= 1
        else:
            d[j] += d[i]
            i += 1
    t = s
    k = sorted(list(zip(d,range(n))), reverse=True)
    lx = rx = s
    for _,i in k:
        if lx <= x[i] <= rx:
            continue
        if lx > x[i]:
            lx = x[i]
        else:
            rx = x[i]
        r += abs(t-x[i])
        t = x[i]


    return r



print(main())