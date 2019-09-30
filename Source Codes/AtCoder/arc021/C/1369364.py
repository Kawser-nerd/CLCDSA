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


def bs(f, mi, ma):
    mm = -1
    while ma > mi:
        mm = (ma+mi) // 2
        if f(mm):
            mi = mm + 1
        else:
            ma = mm
    if f(mm):
        return mm + 1
    return mm


def main():
    K = I()
    N = I()
    A = [LI() for _ in range(N)]

    def f(t):
        c = 0
        for a,d in A:
            if a > t:
                continue
            c += (t-a+d) // d
        return c < K

    k = bs(f,0,10**12)
    t = k-1
    c = 0
    r = 0
    for a,d in A:
        if a > t:
            continue
        ct = (t-a+d) // d
        c += ct
        r += a * ct
        n = ct
        r += (n * (n-1) // 2) * d
    r += (K-c) * k


    return r

print(main())