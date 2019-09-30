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
    s = S()
    s1 = s[:n]
    s2 = s[n:][::-1]
    d1 = collections.defaultdict(int)
    d2 = collections.defaultdict(int)
    ii = [2**_ for _ in range(n)]
    for i in range(2**n):
        t = t2 = t3 = t4 = ','
        for j in range(n):
            if ii[j] & i:
                t += s1[j]
                t3 += s2[j]
            else:
                t2 += s1[j]
                t4 += s2[j]
        d1[t+t2] += 1
        d2[t3+t4] += 1
    r = 0
    for k in d1.keys():
        r += d1[k] * d2[k]

    return r


print(main())