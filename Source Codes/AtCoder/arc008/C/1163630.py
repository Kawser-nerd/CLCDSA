import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7

def LI(): return list(map(int, input().split()))
def LF(): return list(map(float, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()


def main():
    n = II()
    a = [LI() for _ in range(n)]

    d = collections.defaultdict(lambda: inf)
    d[0] = 0
    q = []
    heapq.heappush(q, (0, 0))
    v = collections.defaultdict(bool)
    while len(q):
        k, u = heapq.heappop(q)
        if v[u]:
            continue
        v[u] = True
        ai = a[u]

        for uv in range(1, n):
            if v[uv]:
                continue
            aj = a[uv]
            t = min(ai[2], aj[3]) ** 2
            ud = (((ai[0]-aj[0]) ** 2 + (ai[1]-aj[1]) ** 2) / t) ** 0.5
            vd = k + ud
            if d[uv] > vd:
                d[uv] = vd
                heapq.heappush(q, (vd, uv))

    dl = sorted(list(d.values()), reverse=True)
    r = dl[0]
    for i in range(1, n-1):
        t = dl[i] + i
        if r < t:
            r = t

    return round(r,6)


print(main())