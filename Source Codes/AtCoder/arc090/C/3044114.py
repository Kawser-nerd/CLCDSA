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
    n,m = LI()
    s,t = LI()
    e = collections.defaultdict(list)
    for _ in range(m):
        u,v,d = LI()
        e[u].append((v,d))
        e[v].append((u,d))

    def search(s,t):
        d = collections.defaultdict(lambda: inf)
        dc = collections.defaultdict(int)
        d[s] = 0
        dc[s] = 1
        q = []
        heapq.heappush(q, (0, s))
        v = collections.defaultdict(bool)
        while len(q):
            k, u = heapq.heappop(q)
            if v[u]:
                continue
            v[u] = True

            dc[u] %= mod
            if u == t:
                return (d,dc)

            uc = dc[u]

            for uv, ud in e[u]:
                if v[uv]:
                    continue
                vd = k + ud
                if d[uv] < vd:
                    continue
                if d[uv] > vd:
                    d[uv] = vd
                    dc[uv] = uc
                    heapq.heappush(q, (vd, uv))
                elif d[uv] == vd:
                    dc[uv] += uc

        return (d,dc)

    d1,dc1 = search(s,t)
    d2,dc2 = search(t,s)
    rd = d1[t]
    kk = rd / 2.0

    r = dc1[t] ** 2 % mod
    for k in list(d1.keys()):
        t = d1[k]
        c = dc1[k]
        if t > kk:
            continue
        if t == kk:
            if d2[k] == t:
                r -= pow(c,2,mod) * pow(dc2[k],2,mod) % mod
            continue

        for uv, ud in e[k]:
            if d2[uv] >= kk or t + ud + d2[uv] != rd:
                continue
            r -= pow(c,2,mod) * pow(dc2[uv],2,mod) % mod

    return r % mod




print(main())