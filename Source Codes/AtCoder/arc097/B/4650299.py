class UnionFind:
    def __init__(self, N):
        self.parent = [i for i in range(N)]
        self.rank = [0] * N

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1


N, M = map(int, input().split())
P = list(map(lambda x: int(x) - 1, input().split()))
UF = UnionFind(N)
for _ in range(M):
    x, y = map(lambda x: int(x) - 1, input().split())
    UF.union(x, y)
ans = 0
for i in range(N):
    if UF.find(P[i]) == UF.find(i):
        ans += 1
print(ans)