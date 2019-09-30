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


def M(n): return ModInt(n)
def MI(): return M(I())

class ModInt():
    def __init__(self, n):
        self.n = n

    def __add__(self, x):
        x = ModInt.xn(x)
        return ModInt((self.n+x) % mod)

    def __sub__(self, x):
        x = ModInt.xn(x)
        return ModInt((self.n-x) % mod)

    def __mul__(self, x):
        x = ModInt.xn(x)
        return ModInt((self.n*x) % mod)

    def __truediv__(self, x):
        x = ModInt.xn(x)
        return ModInt(self.n * pow(x, mod-2, mod) % mod)

    @classmethod
    def xn(cls, x):
        if isinstance(x, ModInt):
            return x.n
        return x

    def __str__(self):
        return str(self.n)

def main():
    n,m = LI()
    a = LI_()
    b = [0] * (m*2)
    c = [[] for _ in range(m*2)]
    r = 0
    for i in range(1,n):
        d = a[i-1]
        e = a[i]
        if e < d:
            e += m
        b[d+2] += 1
        c[e].append(e-d-1)
        r += e-d

    f = [0] * (m*2)
    t = 0
    tt = 0
    for i in range(1,m*2):
        t += b[i]
        tt += t
        f[i] += tt
        for g in c[i]:
            t -= 1
            tt -= g
    for i in range(m):
        f[i] += f[i+m]

    return r - max(f)

print(main())