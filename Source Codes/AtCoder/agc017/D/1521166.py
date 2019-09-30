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
    n = I()
    e = collections.defaultdict(set)
    for i in range(n-1):
        a,b = LI()
        e[a].add(b)
        e[b].add(a)

    def f(i,c):
        r = 0
        for j in e[i]:
            if j == c:
                continue
            t = f(j,i)
            r ^= t
        return r + 1

    if f(1,-1) == 1:
        return 'Bob'
    return 'Alice'


print(main())