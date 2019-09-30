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
    a = [LI() for _ in range(n)]
    mm = 0
    mi = 0
    mj = 0
    for i in range(n):
        ai = a[i]
        for j in range(i+1,n):
            aj = a[j]
            t = max(abs(ai[0]-aj[0]), abs(ai[1]-aj[1])) / (1/ai[2]+1/aj[2])
            if mm < t:
                mm = t
                mi = i
                mj = j

    return mm


print(main())