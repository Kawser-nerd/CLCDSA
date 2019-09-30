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
    e = collections.defaultdict(set)
    for a in range(1, n):
        b = I()
        e[a].add(b)
        e[b].add(a)

    m = {}
    def s(i,t):
        key = (i,t)
        if key in m:
            return m[key]
        if len(e[i]) == 1:
            m[key] = [1, n-1]
            return [1, n-1]

        r = []
        for j in e[i]:
            if j == t:
                continue
            k, ma = s(j,i)
            r.append(k)
        if r:
            m[key] = [sum(r)+1, max(r)]
        else:
            m[key] = [1, 0]
        return m[key]

    r = []
    for i in range(n):
        res = s(i, -1)
        r.append(res[1])

    return '\n'.join(map(str, r))


print(main())