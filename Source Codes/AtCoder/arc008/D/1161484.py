import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


class Seg():
    N = 2 ** 20

    def __init__(self, n, default):
        self.N = n
        aa = [[default] * n]
        for i in range(1, 100):
            if len(aa[i-1]) == 1:
                break
            ba = aa[-1]
            l = len(ba) // 2
            a = [self.merge(ba[j*2], ba[j*2+1]) for j in range(l)]
            aa.append(a)
        self.aa = aa

    def update(self, i, x):
        self.aa[0][i] = x
        l = len(self.aa)
        for j in range(1, l):
            i //= 2
            self.aa[j][i] = self.merge(self.aa[j-1][i*2], self.aa[j-1][i*2+1])

    def merge(self, a, b):
        return (a[0] * b[0], a[1] * b[0] + b[1])

    def total(self, x):
        a = self.aa[-1][0]
        return x * a[0] + a[1]


def main():
    n,m = LI()
    aa = [LF() for _ in range(m)]
    keys = set(list(map(lambda x: x[0], aa)))
    keyl = list(keys)
    keyl.sort()
    keyd = {}
    for i in range(len(keyl)):
        keyd[keyl[i]] = i

    seg = Seg(2**17, (1,0))

    mi = ma = seg.total(1)
    for p,a,b in aa:
        seg.update(keyd[p], (a, b))
        t = seg.total(1)
        if mi > t:
            mi = t
        elif ma < t:
            ma = t
    return '\n'.join(list(map(str, [mi,ma])))

print(main())