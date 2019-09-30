import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy

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
    d = [[] for _ in range(n)]
    for _ in range(n-1):
        x,y = LI_()
        d[x].append(y)
        d[y].append(x)

    e = [[] for _ in range(n)]
    f = [-1] * n
    t = []
    ii = [2**i for i in range(20)]

    def ff(i):
        l = len(t)
        f[i] = l
        j = 0
        while ii[j] <= l:
            e[i].append(t[l-ii[j]])
            j += 1
        t.append(i)
        for ni in d[i]:
            if f[ni] >= 0:
                continue
            ff(ni)
        del t[-1]

    ff(0)

    q = I()
    r = []
    for _ in range(q):
        a,b = LI_()
        if f[a] > f[b]:
            a,b = b,a
        tr = f[a] + f[b]
        sa = f[b] - f[a]
        while sa > 0:
            i = 1
            while ii[i] < sa:
                i += 1
            i -= 1
            b = e[b][i]
            sa -= ii[i]
        while a != b:
            i = 1
            le = len(e[a])
            while le > i and e[a][i] != e[b][i]:
                i += 1
            i -= 1
            a = e[a][i]
            b = e[b][i]
        r.append(str(tr - f[a]*2 + 1))

    return '\n'.join(r)

print(main())