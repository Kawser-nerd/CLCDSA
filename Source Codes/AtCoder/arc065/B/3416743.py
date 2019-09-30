# -*- coding: utf-8 -*-
class UnionFind():
    def __init__(self, n):
        self.par = [i for i in range(n)]
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x==y:
            return

        if x<y:
            self.par[y] = x
        else:
            self.par[x] = y
    def same(self, x, y):
        return self.find(x) == self.find(y)


n,k,l = map(int, input().split())
pq = UnionFind(n)
for _ in range(k):
    p,q = map(int, input().split())
    pq.unite(p-1,q-1)
rs = UnionFind(n)
for _ in range(l):
    r,s = map(int, input().split())
    rs.unite(r-1,s-1)

# print(pq.par)
# print(rs.par)
d = {}
for x in range(n):
    a = pq.find(x)
    b = rs.find(x)
    if (a,b) not in d:
        d[(a,b)] = 0
    d[(a,b)] += 1
# print(d)
ret = []
for x in range(n):
    a = pq.find(x)
    b = rs.find(x)
    ret.append(str(d[(a,b)]))

print(" ".join(ret  ))