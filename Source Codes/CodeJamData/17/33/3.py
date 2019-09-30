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
    tt = I()
    rr = []
    for ti in range(1,tt+1):
        n,k = LI()
        c = F()
        a = sorted(LF(), reverse=True)
        for i in range(k-1,-1,-1):
            if i == 0:
                b = 1 - a[i]
            else:
                b = a[i-1] - a[i]
            d = k-i
            if c >= b*d:
                for j in range(d):
                    a[i+j] += b
                c -= b*d
            else:
                for j in range(d):
                    a[i+j] += c/d
                break

        ra = [0] * (n+1)
        ra[0] = 1
        for i in range(n):
            ai = a[i]
            ta = [0] * (n+1)
            for j in range(n):
                ta[j] += ra[j] * (1-ai)
                ta[j+1] += ra[j] * ai
            ra = ta

        rr.append('Case #{}: {}'.format(ti, sum(ra[k:])))

    return '\n'.join(rr)


print(main())
