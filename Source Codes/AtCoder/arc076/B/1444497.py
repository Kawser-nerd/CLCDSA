class UnionFind(object):

    def __init__(self, n):
        self.n = n
        self.par = list(range(n))
        self.rank = [1] * n

    def is_same(self, a, b):
        return self.root(a) == self.root(b)

    def root(self, x):
        if self.par[x] == x:
            return x
        self.par[x] = self.root(self.par[x])
        return self.par[x]

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return
        if self.rank[x] > self.rank[y]:
            self.par[y] = x
        elif self.rank[x]  < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            self.rank[x] += 1


N = int(input())
X = []
Y = []
for i in range(N):
    x, y = map(int, input().split())
    X.append((x, i))
    Y.append((y, i))

X = sorted(X)
Y = sorted(Y)
graph = []
for i in range(N - 1):
    graph.append((X[i + 1][0] - X[i][0], X[i][1], X[i + 1][1]))
    graph.append((Y[i + 1][0] - Y[i][0], Y[i][1], Y[i + 1][1]))

graph.sort()
uf = UnionFind(N)

total_cost = 0
for cost, a, b in graph:
    if not uf.is_same(a, b):
        uf.unite(a, b)
        total_cost += cost

print(total_cost)