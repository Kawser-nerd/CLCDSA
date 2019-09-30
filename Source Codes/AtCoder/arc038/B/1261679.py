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
    h,w = LI()
    a = [[c == '.' for c in S()] + [False] for _ in range(h)]
    a += [[False] * (w+1)]

    m = {}
    def f(i,j):
        if not a[i][j]:
            return True
        k = (i,j)
        if k in m:
            return m[k]

        if f(i+1,j) and f(i,j+1) and f(i+1,j+1):
            m[k] = False
        else:
            m[k] = True
        return m[k]

    if f(0,0):
        return 'First'
    return 'Second'


print(main())