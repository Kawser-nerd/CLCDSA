# Union-Find?????
class UnionFind:
    def __init__(self, numV):
        self.pars = [i for i in range(numV)]
        self.ranks = [0] * numV

    def find(self, x):
        if self.pars[x] == x:
            return x
        else:
            self.pars[x] = self.find(self.pars[x])
            return self.pars[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.ranks[x] < self.ranks[y]:
            self.pars[x] = y
        else:
            self.pars[y] = x
            if self.ranks[x] == self.ranks[y]:
                self.ranks[x] += 1


N, K, L = map(int, input().split())
pqs = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(K)]
rss = [tuple(map(lambda x: int(x) - 1, input().split())) for _ in range(L)]

# ??
UFRoad = UnionFind(N)
for p, q in pqs:
    UFRoad.union(p, q)

# ??
UFRailway = UnionFind(N)
for r, s in rss:
    UFRailway.union(r, s)

Ts = [(UFRoad.find(i), UFRailway.find(i), i) for i in range(N)] + [(N, N, N)]
Ts.sort()

anss = [0] * N
iFr = 0
for i in range(N):
    if Ts[i][0:2] != Ts[i + 1][0:2]:
        for j in range(iFr, i + 1):
            anss[Ts[j][2]] = i - iFr + 1
        iFr = i + 1

print(' '.join(map(str, anss)))