import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
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
        return mm
    return mm-1

def main():
    n,w = LI()
    a = [tuple(LI()) for _ in range(n)]
    if all(map(lambda x: x[1] <= 1000, a)):
        t = [0] * 200000
        a = sorted(a, key=lambda x: (x[1],x[0]))
        m = 0
        for c,b in a:
            for i in range(m,-1,-1):
                if t[i]+c > t[i+b]:
                    t[i+b] = t[i]+c
            m += b
        return max(t[:min(w+1, 200000)])

    if all(map(lambda x: x[0] <= 1000, a)):
        t = [inf] * 200000
        t[0] = 0
        a = sorted(a)
        m = 0
        for c,b in a:
            for i in range(m,-1,-1):
                if t[i]+b < t[i+c]:
                    t[i+c] = t[i]+b
            m += c
        return max([i for i in range(200000) if t[i] <= w])

    al_2 = len(a)//2
    a1 = a[:al_2]
    a2 = a[al_2:]

    def f(a):
        r = set()
        r.add((0,0))
        for i in range(len(a)):
            ai1,ai0 = a[i]
            t = set()
            t.add((ai0,ai1))
            for c in r:
                t.add((c[0]+ai0,c[1]+ai1))
            r |= t
        rl = sorted(list(r))
        return list(rl[i] for i in range(len(rl)) if (i<1 or rl[i-1][1] < rl[i][1]))

    s2 = f(a1)
    s1 = f(a2)
    s2l = len(s2)
    r = 0
    for c in s1:
        i = bisect.bisect_left(s2, (w-c[0], inf))
        if i == 0:
            continue
        if r < c[1] + s2[i-1][1]:
            r = c[1] + s2[i-1][1]

    return r


print(main())