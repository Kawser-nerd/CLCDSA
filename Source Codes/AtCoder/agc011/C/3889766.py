# ??
# https://atcoder.jp/contests/agc011/submissions/1157055

class UnionFind:
    def __init__(self, n):
        self.v = [-1 for _ in range(n)]

    def find(self, x):
        if self.v[x] < 0:
            return x
        else:
            self.v[x] = self.find(self.v[x])
            return self.v[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if -self.v[x] < -self.v[y]:
            x, y = y, x
        self.v[x] += self.v[y]
        self.v[y] = x

    def root(self, x):
        return self.v[x] < 0

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def size(self, x):
        return -self.v[self.find(x)]


N, M = map(int, input().split())
uf = UnionFind(2 * N)
for _ in range(M):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    uf.unite(u, N + v)
    uf.unite(N + u, v)

alone = 0
bi = 0
unko = 0

for u in range(N):
    if uf.root(u) or uf.root(N + u):
        if uf.size(u) == 1:
            alone += 1
        elif uf.same(u, N + u):
            unko += 1
        else:
            bi += 1

ans = 0
ans += alone * N
ans += N * alone
ans -= alone * alone
ans += bi * bi * 2
ans += bi * unko
ans += unko * bi
ans += unko * unko

print(ans)