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
    d = sorted([I() for _ in range(n)])

    a = [1] * n
    for _ in range(3):
        j = 1
        t = [0] * n
        for i in range(n):
            i2 = d[i]*2
            while j < n and d[j] < i2:
                j += 1
            if j == n:
                break
            t[j] += a[i]
        for i in range(1,n):
            t[i] += t[i-1]
        a = t
    return sum(a) % mod


print(main())