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
    fi,la = LS()
    N = I()
    if fi == la:
        return '\n'.join(['0', fi, la])
    sn = [S() for _ in range(N)]
    sl = [fi,la]
    ss = set(sl)
    for s in sn:
        if s in ss:
            continue
        sl.append(s)
        ss.add(s)

    e = collections.defaultdict(list)
    l = len(sl)
    ll = len(fi)
    def ff(a,b):
        c = 0
        for i in range(ll):
            if a[i] != b[i]:
                c += 1
                if c > 1:
                    return False
        return True

    for i in range(l):
        a = sl[i]
        for j in range(i+1,l):
            if ff(a, sl[j]):
                e[i].append((j,1))
                e[j].append((i,1))

    def search(s):
        d = collections.defaultdict(lambda: [inf,-1])
        d[s] = [0,-1]
        q = []
        heapq.heappush(q, (0, s))
        v = collections.defaultdict(bool)
        while len(q):
            k, u = heapq.heappop(q)
            if v[u]:
                continue
            v[u] = True

            for uv, ud in e[u]:
                if v[uv]:
                    continue
                vd = k + ud
                if d[uv][0] > vd:
                    d[uv] = [vd,u]
                    heapq.heappush(q, (vd, uv))

        return d

    d = search(0)
    if d[1][0] == inf:
        return -1
    r = []
    t = 1
    while d[t][1] >= 0:
        r.append(sl[t])
        t = d[t][1]
    r.append(fi)
    r.append(str(d[1][0]-1))
    r.reverse()

    return '\n'.join(r)



print(main())