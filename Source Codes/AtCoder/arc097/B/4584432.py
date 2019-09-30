class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n + 1)]
        self.rank = [0] * (n + 1)
        self.size = [1] * (n + 1)

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            if self.same_check(x, y) != True:
                self.size[y] += self.size[x]
                self.size[x] = 0
            self.par[x] = y
        else:
            if self.same_check(x, y) != True:
               self.size[x] += self.size[y]
               self.size[y] = 0
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
               self.rank[x] += 1

    def siz(self, x):
        x = self.find(x)
        return self.size[x]


N, M = list(map(int, input().split()))
p = list(map(int, input().split()))

uf = UnionFind(N)
for i in range(M):
    x, y = list(map(int, input().split()))
    uf.union(x, y)

c = 0
for i in range(N):
    if uf.find(p[i]) == uf.find(i + 1):
        c += 1

print(c)