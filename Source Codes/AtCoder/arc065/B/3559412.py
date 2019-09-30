from collections import Counter
N,K,L = map(int,input().split())
P = [tuple(map(int,input().split())) for i in range(K)]
R = [tuple(map(int,input().split())) for i in range(L)]

class UnionFind:
    def __init__(self,N):
        self.parent = [i for i in range(N)]
        self.rank = [0] * N
        self.count = 0
    def root(self,a):
        if self.parent[a] == a:
            return a
        else:
            self.parent[a] = self.root(self.parent[a])
            return self.parent[a]
    def is_same(self,a,b):
        return self.root(a) == self.root(b)
    def unite(self,a,b):
        ra = self.root(a)
        rb = self.root(b)
        if ra == rb: return
        if self.rank[ra] < self.rank[rb]:
            self.parent[ra] = rb
        else:
            self.parent[rb] = ra
            if self.rank[ra] == self.rank[rb]: self.rank[ra] += 1
        self.count += 1

uf1 = UnionFind(N)
for p,q in P:
    p,q = p-1,q-1
    if uf1.is_same(p,q): continue
    uf1.unite(p,q)

uf2 = UnionFind(N)
for r,s in R:
    r,s = r-1,s-1
    if uf2.is_same(r,s): continue
    uf2.unite(r,s)

pairs = Counter()
for i in range(N):
    a = uf1.root(i)
    b = uf2.root(i)
    pairs[(a,b)] += 1

ans = []
for i in range(N):
    a = uf1.root(i)
    b = uf2.root(i)
    ans.append(pairs[(a,b)])
print(*ans)