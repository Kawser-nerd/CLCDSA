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
    n = I()
    aa = LI()
    a = [set([_]) for _ in aa]
    b = LI()

    e = [[None]*51 for _ in range(51)]
    for i in range(51):
        for j in range(i+1):
            if i == j:
                e[i][j] = 0
                continue
            if j == 0:
                e[i][0] = 1
                continue
            for k in range(1,i,1):
                ik = i % k
                if ik == j or ik > j*2:
                    e[i][j] = k
                    break

    for i in range(n):
        if e[aa[i]][b[i]] is None:
            return -1

    def f():
        r = -1
        for i in range(n):
            tr = inf
            for d in a[i]:
                if e[d][b[i]] < tr:
                    tr = e[d][b[i]]
            if r < tr:
                r = tr

        return r

    rr = 0

    while 1:
        k = f()
        if k == 0:
            break
        for i in range(n):
            for c in list(a[i]):
                at = c % k
                if e[at][b[i]] is not None:
                    a[i].add(at)
        rr |= 2**k


    return rr


print(main())