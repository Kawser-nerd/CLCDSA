import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
gosa = 1.0 / 10**10
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()

def distance(x1, y1, x2, y2):
    return math.sqrt((x1-x2)**2 + (y1-y2)**2)

def radian(x1, y1, x2, y2):
    return math.atan2(y2-y1, x2-x1)

# (distance, radian)
def drx(d, r):
    return math.cos(r) * d

def dry(d, r):
    return math.sin(r) * d


def main():
    x,y = LI()
    n = I()
    a = [LI() for _ in range(n)]
    r = inf
    for i in range(n):
        x1,y1 = a[i-1]
        x2,y2 = a[i]
        d = distance(x,y, x1,y1)
        r1 = radian(x1,y1, x2,y2)
        r2 = radian(x1,y1, x,y)
        r2 -= r1
        if r2 > math.pi:
            r2 = r2 % math.pi - math.pi
        elif r2 < -math.pi:
            r2 = math.pi - (-r2 % math.pi)
        tr = dry(d, r2)
        if tr < r:
            r = tr

    return r


print(main())