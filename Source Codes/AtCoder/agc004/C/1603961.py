import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()


def main():
    h,w = LI()
    a = [[c == '#' for c in S()] for _ in range(h)]
    r = ['#' * w]
    for c in a[1:-1]:
        t = ''
        for i in range(w):
            ci = c[i]
            if ci or i % 2 == 0:
                t += '#'
            else:
                t += '.'
        r.append(t)
    r.append('.' * w)
    r.append('')
    r.append('.' * w)
    for c in a[1:-1]:
        t = ''
        for i in range(w):
            ci = c[i]
            if ci or i % 2 == 1:
                t += '#'
            else:
                t += '.'
        r.append(t)

    r.append('#' * w)

    return '\n'.join(r)


print(main())