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
    n,q = LI()
    a = [LI() for _ in range(n)]
    ra = [0] * (10**4*2+1)
    pi3 = math.pi / 3
    for x,r,h in a:
        for i in range(h):
            ri = r * (h-i)/h
            rj = r * (h-i-1)/h
            ra[x+i] += ri**2*(h-i)*pi3 - rj**2*(h-i-1)*pi3

    k = [0] * (10**4*2+1)
    k[0] = ra[0]
    for i in range(1,10**4*2+1):
        k[i] = k[i-1] + ra[i]


    rr = []
    for _ in range(q):
        c,d = LI()
        if c == 0:
            rr.append(str(k[d-1]))
        else:
            rr.append(str(k[d-1]-k[c-1]))

    return '\n'.join(rr)


print(main())