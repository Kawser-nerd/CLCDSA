class DisjointSet:
    def __init__(self):
        self.rank = {}
        self.p = {}

    def makeSet(self, x):
        self.p[x] = x
        self.rank[x] = 0

    def same(self, x, y):
        return self.findSet(x) == self.findSet(y)

    def unite(self, x, y):
        self.link(self.findSet(x), self.findSet(y))

    def link(self, x, y):
        if x == y:
            return
        if(self.rank[x] > self.rank[y]):
            self.p[y] = x
        else:
            self.p[x] = y
            if(self.rank[x] == self.rank[y]):
                self.rank[y] += 1

    def findSet(self, x):
        if(x != self.p[x]):
            self.p[x] = self.findSet(self.p[x])
        return self.p[x]

N, M = map(int, input().split())
ds = DisjointSet()
for i in range(1, N+1):
    ds.makeSet(i)

for i in range(M):
    a, b = map(int, input().split())
    ds.unite(a, b)

connected_component = 0

for i in range(1, N+1):
    if i == ds.findSet(i):
        connected_component += 1

print(connected_component-1)