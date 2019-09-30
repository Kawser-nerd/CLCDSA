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


def main():
    a = S()
    l = len(a)
    t = {}
    for c in string.ascii_lowercase:
        t[c] = l
    b = [(1,0,0) for _ in range(l)]
    b.append((1,'a',l))
    b.append((0,'',l+1))

    for c,i in reversed(list(zip(a,range(l)))):
        t[c] = i
        b[i] = min([(b[t[d]+1][0] + 1,d,t[d]+1) for d in string.ascii_lowercase])

    r = ''
    i = 0
    while i < l:
        r += b[i][1]
        i = b[i][2]
    return r

print(main())