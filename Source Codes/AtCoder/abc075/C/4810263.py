N, M = map(int, input().split())
ab = [tuple(map(int, input().split())) for _ in range(M)]

class UnionFind:
    def __init__(self, N):
        self.size = N
        self.par = [None] * N
        self.rank = [None] * N
        for n in range(N):
            self.par[n] = n
            self.rank[n] = 1

    def root(self, x):
        if self.par[x] == x:
            return x
        r = self.root(self.par[x])
        self.par[x] = r
        return r

    def unite(self, x, y):
        rx = self.root(x)
        ry = self.root(y)
        if rx != ry:
            self.size -= 1
            if self.rank[rx] > self.rank[ry]:
                self.par[ry] = rx
            else:
                self.par[rx] = ry
                if self.rank[rx] == self.rank[ry]:
                    self.rank[ry] += 1

    def is_same(self, x, y):
        return self.root(x) == self.root(y)

c = 0
for i in range(M):
    # i ????????????????????????
    uf = UnionFind(N)
    for a, b in ab[0:i]+ab[i+1:M]:
        uf.unite(a-1, b-1)
    if uf.size > 1:
        c += 1
print(c)