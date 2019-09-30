class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n+1)]
        self.rank = [0] * (n+1)

    # ??
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # ??
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    # ???????????
    def same_check(self, x, y):
        return self.find(x) == self.find(y)

N, M = [int(x) for x in input().split()]

uf = UnionFind(N)
p = [int(x) for x in input().split()]
for m in range(M):
    x, y = [int(x) for x in input().split()]
    uf.union(x, y)

res = 0
for i in range(N):
    if uf.same_check(i+1, p[i]):
        res += 1
print(res)