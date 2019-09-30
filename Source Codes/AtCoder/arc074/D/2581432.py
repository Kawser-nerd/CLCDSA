import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**15
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)

class E:
    def __init__(self, dst, cap, rev):
        self.dst = dst
        self.cap = cap
        self.rev = rev

    def __repr__(self):
        return "({}, {}, {})".format(self.dst, self.cap, self.rev)

    def __str__(self):
        return "({}, {}, {})".format(self.dst, self.cap, self.rev)

class Dinic:
    def __init__(self, n):
        self.n = n
        self.g = [[] for _ in range(n)]

    def add_edge(self, src, dst, cap):
        self.g[src].append(E(dst, cap, len(self.g[dst])))
        self.g[dst].append(E(src, 0, len(self.g[src]) - 1))

    def add_undirected_edge(self, src, dst, cap):
        self.g[src].append(E(dst, cap, len(self.g[dst])))
        self.g[dst].append(E(src, cap, len(self.g[src]) - 1))

    def dfs(self, s, u, crr):
        if s == u or crr == 0:
            return crr
        sm = 0
        for i in range(self.itr[u], len(self.g[u])):
            e = self.g[u][i]
            ee = self.g[e.dst][e.rev]
            v = e.dst
            if self.level[v] >= self.level[u] or ee.cap <= 0:
                continue
            f = self.dfs(s, v, min(crr - sm, ee.cap))
            if f <= 0:
                continue
            ee.cap -= f
            e.cap += f
            sm += f
            if sm == crr:
                break
        return sm

    def run(self, s, t):
        q = [0] * self.n
        flow = 0
        while True:
            self.level = [-1] * self.n
            q[0] = s
            self.level[s] = 0
            ql = 0
            qr = 1
            while ql != qr and self.level[t] == -1:
                u = q[ql]
                ql += 1
                for e in self.g[u]:
                    if e.cap > 0 and self.level[e.dst] == -1:
                        self.level[e.dst] = self.level[u] + 1
                        q[qr] = e.dst
                        qr += 1
            if self.level[t] == -1:
                return flow
            self.itr = [0] * self.n
            flow += self.dfs(s, t, inf)

        return flow

def main():
    h,w = LI()
    a = [S() for _ in range(h)]
    dn = Dinic(h+w+2)
    s = h+w
    t = s+1
    for i in range(h):
        for j in range(w):
            c = a[i][j]
            if c == '.':
                continue
            if c == 'o':
                dn.add_undirected_edge(i, h+j, 1)
            elif c == 'S':
                dn.add_edge(s, i, inf)
                dn.add_edge(s, h+j, inf)
                for ii in range(h):
                    a
            elif c == 'T':
                dn.add_edge(i, t, inf)
                dn.add_edge(h+j, t, inf)

    r = dn.run(s, t)
    if r >= inf:
        return -1
    return r




print(main())