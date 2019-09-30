f = lambda: list(map(int,input().split()))
f_ = lambda: [int(x)-1 for x in input().split()]


class UnionFind(object):
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)


n,k,l = f()
ud = UnionFind(n)
for _ in range(k):
    p,q = f_()
    ud.unite(p,q)
ut = UnionFind(n)
for _ in range(l):
    p,q = f_()
    ut.unite(p,q)

p = [(ud.find(i),ut.find(i)) for i in range(n)]

from collections import Counter
c = Counter(p)
print(*[c[p[i]] for i in range(n)])