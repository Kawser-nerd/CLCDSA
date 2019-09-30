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
    n = I()
    a = []
    b = []
    d = []
    for _ in range(n):
        x,y = LI()
        if x < y:
            a.append([x,y])
        else:
            b.append([x,y])

    r = 0
    c = 0
    a = sorted(a)
    for x,y in a:
        c += x
        if r < c:
            r = c
        c -= y

    b = sorted(b, key=lambda x: [-x[1],-x[0]])
    for x,y in b:
        c += x
        if r < c:
            r = c
        c -= y

    return r


print(main())