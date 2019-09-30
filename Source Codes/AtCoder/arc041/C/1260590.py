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
    n,l = LI()
    a = []
    for _ in range(n):
        x,d = LS()
        if d == 'L':
            a.append([int(x),1])
        else:
            a.append([int(x),2])

    r = 0
    i = 0
    while i < n and a[i][1] == 1:
        r += a[i][0] - i - 1
        i += 1

    j = n-1
    while j > -1 and a[j][1] == 2:
        r += l - a[j][0] - (n-1-j)
        j -= 1

    if i > j:
        return r

    k = i
    while k <= j:

        rk = k
        while a[k][1] == 2:
            k += 1
        rx = a[k-1][0]
        for t in range(rk,k):
            r += (rx-a[t][0]) - (k-t-1)
        rc = k - rk

        lk = k
        while k < n and a[k][1] == 1:
            k += 1
        lx = a[lk][0]
        for t in range(lk,k):
            r += (a[t][0]-lx) - (k-t-1)
        lc = k - lk

        r += max(rc,lc) * (a[lk][0]-a[lk-1][0]-1)

    return r


print(main())