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
    R,C,N = LI()
    a = []
    def ff(x,y):
        if x == 0:
            return (0,y)
        if x == R:
            return (R,-y)
        if y == 0:
            return (R+1, -x)
        return (1, x)

    for _ in range(N):
        x1,y1,x2,y2 = LI()
        if (0 < x1 < R and 0 < y1 < C) or (0 < x2 < R and 0 < y2 < C):
            continue
        a.append((ff(x1,y1),_))
        a.append((ff(x2,y2),_))
    a.sort()
    b = [a[i][1] for i in range(len(a))]
    s = [None] * (len(b))
    si = -1
    for c in b:
        if si < -1:
            si += 1
            s[0] = c
            continue
        if s[si] == c:
            si -= 1
        else:
            si += 1
            s[si] = c

    if si > 1:
        return 'NO'
    return 'YES'

print(main())