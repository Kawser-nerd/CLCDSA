from collections import defaultdict

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

N = int(input())
xd = defaultdict(lambda: [])
yd = defaultdict(lambda: [])
for i in range(N):
    x,y = map(int,input().split())
    xd[x].append(i)
    yd[y].append(i)

uf = UnionFind(N)
es = []
pre_x = pre_i = None
for x,idxs in sorted(xd.items()):
    if len(idxs) >= 2:
        for i1,i2 in zip(idxs,idxs[1:]):
            if uf.is_same(i1,i2): continue
            uf.unite(i1,i2)
    if pre_x is not None:
        dx = x - pre_x
        es.append((dx,pre_i,idxs[0]))
    pre_x = x
    pre_i = idxs[0]
pre_y = pre_i = None
for y,idxs in sorted(yd.items()):
    if len(idxs) >= 2:
        for i1,i2 in zip(idxs,idxs[1:]):
            if uf.is_same(i1,i2): continue
            uf.unite(i1,i2)
    if pre_y is not None:
        dy = y - pre_y
        es.append((dy,pre_i,idxs[0]))
    pre_y = y
    pre_i = idxs[0]

if uf.count == N-1:
    print(0)
    exit()
ans = 0
for cost,a,b in sorted(es):
    if uf.is_same(a,b): continue
    uf.unite(a,b)
    ans += cost
    if uf.count == N-1:
        break
print(ans)