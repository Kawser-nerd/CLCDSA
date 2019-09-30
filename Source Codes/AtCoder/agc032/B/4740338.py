import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n = I()
    rr = []
    g = []
    if n % 2 == 1:
        g.append([n])
        n -= 1
    for i in range(1,n//2+1):
        g.append([i,n-i+1])

    l = len(g)
    for i in range(l):
        for j in range(i+1,l):
            for c in g[i]:
                for d in g[j]:
                    rr.append('{} {}'.format(c, d))

    return '{}\n{}'.format(len(rr), '\n'.join(rr))


print(main())