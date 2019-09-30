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
    a,b = LI()
    d = collections.defaultdict(int)
    for i in range(b+1,a+1):
        while i % 2 == 0:
            d[2] += 1
            i //= 2
        for j in range(3,10**5,2):
            while i % j == 0:
                d[j] += 1
                i //= j
            if i < j:
                d[i] += 1
                break
        if i >= 10**5:
            d[i] += 1

    r = 1
    d[1] = 0
    for v in d.values():
        r *= v+1
        r %= mod

    return r


print(main())