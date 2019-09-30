import array
import collections


class UnionFind(object):
    def __init__(self, number_of_nodes):
        # Don't use self.par directly! (call self.root)
        self.par = array.array("L", range(number_of_nodes))
        self.rank = array.array("L", (0 for _ in range(number_of_nodes)))

    def root(self, node):
        if self.par[node] == node:
            return node
        else:
            r = self.root(self.par[node])
            self.par[node] = r
            return r

    def in_the_same_set(self, node1, node2):
        return self.root(node1) == self.root(node2)

    def unite(self, node1, node2):
        x = self.root(node1)
        y = self.root(node2)
        if x == y:
            pass
        elif self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

n, k, l = map(int, input().split())
roads = [map(int, input().split()) for _ in range(k)]
trains = [map(int, input().split()) for _ in range(l)]

uf1 = UnionFind(n+1)
for p, q in roads:
  uf1.unite(p, q)

uf2 = UnionFind(n+1)
for r, s in trains:
  uf2.unite(r, s)

count = collections.Counter([(uf1.root(i), uf2.root(i)) for i in range(1,n+1)])

print(' '.join([str(count[(uf1.root(i), uf2.root(i))]) for i in range(1,n+1)]))