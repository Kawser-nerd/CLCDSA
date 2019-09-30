import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**10
mod = 10**9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    x,y = [int(x) for x in sys.stdin.readline().split('/')]
    g = fractions.gcd(x,y)
    x //= g
    y //= g
    it = int(x/y) * 2
    r = []
    for i in range(max(1,it-10), it+10):
        k = (i+1)*i // 2
        if i % y != 0:
            continue
        t = k - (i//y) * x
        if 0 < t <= i:
            r.append([i,t])

    if r:
        return '\n'.join([' '.join(map(str, _)) for _ in r])
    return 'Impossible'


print(main())