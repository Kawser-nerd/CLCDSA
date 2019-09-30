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
    H,W,h,w = LI()
    f = False
    if H % h == 0 and W % w == 0:
        return 'No'
    if W % w == 0:
        H,W,h,w = W,H,w,h
        f = True

    p = 10**6*(w-1) - 1
    m = -(10**6)
    a = []
    for i in range(W):
        if i % w == 0:
            a.append(p)
        else:
            a.append(m)
    aa = [a] * H
    r = aa
    if f:
        r = [[aa[i][j] for i in range(H)] for j in range(W)]

    return 'Yes\n' + '\n'.join(' '.join(map(str,t)) for t in r)


print(main())