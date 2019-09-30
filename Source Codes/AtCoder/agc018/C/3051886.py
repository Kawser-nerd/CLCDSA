import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    X,Y,Z = LI()
    xyz = sorted([LI() for _ in range(X+Y+Z)], key=lambda x: x[0]-x[1])
    ys = xyz[:Y]
    yq = []
    tr = 0
    for x,y,z in ys:
        heapq.heappush(yq, y-z)
        tr += y
    ya = [tr]
    for i in range(Z):
        x,y,z = xyz[Y+i]
        tr += y
        heapq.heappush(yq, y-z)
        t = heapq.heappop(yq)
        tr -= t
        ya.append(tr)

    xs = xyz[Y+Z:]
    xq = []
    tr = 0
    for x,y,z in xs:
        heapq.heappush(xq, x-z)
        tr += x
    xa = [tr]
    for i in range(Z):
        x,y,z = xyz[-X-i-1]
        tr += x
        heapq.heappush(xq, x-z)
        t = heapq.heappop(xq)
        tr -= t
        xa.append(tr)

    r = 0
    for a,b in zip(ya, xa[::-1]):
        tr = a+b
        if r < tr:
            r = tr

    return r




print(main())