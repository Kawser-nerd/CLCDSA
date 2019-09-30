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


def ccw(a, b, c):
    ax = b[0] - a[0]
    ay = b[1] - a[1]
    bx = c[0] - a[0]
    by = c[1] - a[1]
    t = ax*by - ay*bx;
    if t > 0:
        return 1
    if t < 0:
        return -1
    if ax*bx + ay*by < 0:
        return 2
    if ax*ax + ay*ay < bx*bx + by*by:
        return -2
    return 0

def convex_hull(ps):
    n = len(ps)
    k = 0
    ps.sort()
    ch = [[-1,-1] for _ in range(n*2)]
    for i in range(n):
        while k >= 2 and ccw(ch[k-2], ch[k-1], ps[i]) <= 0:
            k -= 1
        ch[k] = ps[i]
        k += 1
    t = k + 1
    for i in range(n-2,-1,-1):
        while k >= t and ccw(ch[k-2], ch[k-1], ps[i]) <= 0:
            k -= 1
        ch[k] = ps[i]
        k += 1
    ch = ch[:k-1]
    return ch

def radian(a, b):
    return math.atan2(b[1]-a[1], b[0]-a[0])

def main():
    n = I()
    a = [LI() + [_] for _ in range(n)]
    t = convex_hull(a)
    l = len(t)
    r = [0] * n
    if l == 2:
        r[t[0][2]] = 0.5
        r[t[1][2]] = 0.5
    else:
        for i in range(l):
            r1 = radian(t[i], t[i-1])
            r2 = radian(t[i], t[(i+1) % l])
            k = r2 - r1
            while k < 0:
                k += math.pi * 2
            e = (k-math.pi) / math.pi / 2
            r[t[i][2]] = e

    return '\n'.join(map(str,r))


print(main())