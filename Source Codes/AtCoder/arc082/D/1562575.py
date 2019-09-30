import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**10
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    x = I()
    k = I()
    r = LI()
    q = I()
    t = [LI() for _ in range(q)]
    a = [[0,0,0,x,0,0]]
    d = 0
    for i in range(k):
        c = a[-1][:]
        rr = r[i] - d
        d = r[i]
        if i % 2 == 0:
            c[1] -= rr
            c[3] -= rr
            c[4] -= rr
            if c[0] > c[1]:
                c[0] = c[1]
        else:
            c[1] += rr
            c[3] += rr
            c[4] += rr
            if c[2] < c[1]:
                c[2] = c[1]
        if c[3] > x:
            c[3] = x
        if c[3] < 0:
            c[3] = 0
        if c[4] > x:
            c[4] = x
        if c[4] < 0:
            c[4] = 0

        c[5] = r[i]

        a.append(c)
    def bs(i):
        ma = k
        mi = 0
        mm = 0
        while ma > mi and (ma+mi) // 2 != mm:
            mm = (ma+mi) // 2
            if a[mm][5] < i:
                mi = mm
            else:
                ma = mm - 1
        if a[mm][5] > i:
            return mm-1
        if mm == k:
            return k
        if a[mm+1][5] <= i:
            return mm+1
        return mm

    #print(a)
    rr = []
    for c,d in t:
        ti = bs(c)
        ai = a[ti]
        e = x-d
        #print(c,d,e,ti,ai)
        if d + ai[0] <= 0:
            tt = ai[4]
        elif e - ai[2] <= 0:
            tt = ai[3]
        else:
            tt = d + ai[1]
        #print('tt',tt)
        if ti % 2 == 0:
            tt -= c - ai[5]
        else:
            tt += c - ai[5]
        #print('tt2',tt)
        if tt < 0:
            tt = 0
        elif tt > x:
            tt = x
        rr.append(tt)

    return '\n'.join(map(str,rr))


print(main())