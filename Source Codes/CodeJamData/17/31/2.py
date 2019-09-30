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
        a = []
        for _ in range(n):
            b,c = LI()
            m = b*b*math.pi
            l = b*2*math.pi*c
            a.append([b,m,l])
        a = sorted(a, reverse=True)
        r = 0
        for i in range(n-k+1):
            tr = a[i][1] + a[i][2]
            ta = sorted(a[i+1:], key=lambda x: -x[2])
            tr += sum(map(lambda x: x[2], ta[:k-1]))
            if r < tr:
                r = tr

        rr.append('Case #{}: {}'.format(ti, r))

    return '\n'.join(rr)


print(main())
