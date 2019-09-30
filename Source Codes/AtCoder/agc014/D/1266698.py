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
    n = I()
    d = collections.defaultdict(set)
    kk = None
    for _ in range(n-1):
        a,b = LI()
        kk = [a,b]
        d[a].add(b)
        d[b].add(a)

    tt = True
    gf = collections.defaultdict(bool)
    while tt:
        tt = False
        for k,v in list(d.items()):
            if len(v) == 1:
                vt = list(v)[0]
                if len(d[vt]) == 1:
                    continue
                for vv in d[vt]:
                    if vv == k:
                        continue
                    if vt in d[vv]:
                        d[vv].remove(vt)
                d[vt] = set([k])
                tt = True
            elif len(v) == 0:
                return 'First'
    return 'Second'


print(main())