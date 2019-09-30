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


def main():
    N,X = LI()
    W = sorted([I() for _ in range(N)], reverse=True)
    d = collections.defaultdict(int)
    d[0] = 1
    for c in W[N//2:]:
        t = collections.defaultdict(int)
        for k,v in d.items():
            if k+c > X:
                continue
            t[k+c] += v
        for k,v in t.items():
            d[k] += v
    d2 = collections.defaultdict(int)
    d2[0] = 1
    for c in W[:N//2]:
        t = collections.defaultdict(int)
        for k,v in d2.items():
            if k+c > X:
                continue
            t[k+c] += v
        for k,v in t.items():
            d2[k] += v
    r = 0
    for k,v in d.items():
        r += v * d2[X-k]


    return r


print(main())