import array, collections

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

n, m, s = list(map(int, input().split()))
g = collections.defaultdict(list)
for _ in range(m):
  u, v = list(map(int, input().split()))
  g[u].append(v)
  g[v].append(u)

uf = UnionFind(n+1)
ans = []
for i in range(n, 0, -1):
  for vi in g[i]:
    if vi > i: uf.unite(i, vi)
  if uf.in_the_same_set(s, i):
    ans.append(i)

ans.sort()

print('\n'.join(map(str, ans)))