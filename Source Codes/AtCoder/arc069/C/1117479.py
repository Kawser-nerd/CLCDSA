import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


def main():
    n = II()
    a = LI()
    b = [(a[i], i) for i in range(n)]
    b.sort()
    b.reverse()
    r = [0] * n
    s = sum(a)
    t = inf
    for i in range(n):
        ai,bi = b[i][0],b[i][1]
        if bi == 0:
            r[0] += s
            break
        ti = (ai - b[i+1][0]) * (i+1)
        if t > bi:
            t = bi
        r[t] += ti
        s -= ti
    return '\n'.join(map(str, r))

print(main())