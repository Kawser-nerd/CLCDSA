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
    h,w,k = LI()
    a = []
    st = None
    for i in range(h):
        s = S()
        if 'S' in s:
            st = [i, s.index('S')]
        a.append([c=='#' for c in s])

    def ns(k):
        i,j = k
        r = []
        if i < h-1:
            r.append((i+1,j))
        if j < w-1:
            r.append((i,j+1))
        if i > 0:
            r.append((i-1,j))
        if j > 0:
            r.append((i,j-1))
        return r


    def search(ss,tk):
        d = collections.defaultdict(lambda: inf)
        q = []
        for s in ss:
            d[s] = 0
            heapq.heappush(q, (0, s))
        v = collections.defaultdict(bool)
        while len(q):
            k, u = heapq.heappop(q)
            if k >= tk:
                break
            if v[u]:
                continue
            v[u] = True

            for nu in ns(u):
                if v[nu] or a[nu[0]][nu[1]]:
                    continue
                vd = k + 1
                if d[nu] > vd:
                    d[nu] = vd
                    if nu[0] == 0 or nu[1] == 0 or nu[0] == h-1 or nu[1] == w-1:
                        return d
                    heapq.heappush(q, (vd, nu))

        return d

    d = search([tuple(st)],k)
    r = inf
    hs = []
    ws = []
    for g in d.keys():
        if 0 < g[0] < h-1 and 0 < g[1] < w-1:
            hs.append(g[0])
            ws.append(g[1])
            continue
        return 1

    return (min(min(hs),min(ws),h-max(hs)-1,w-max(ws)-1) + k - 1) // k + 1

print(main())