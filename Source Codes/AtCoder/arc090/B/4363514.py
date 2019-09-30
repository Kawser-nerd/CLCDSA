# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline


class WeightedUnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n+1)]
        self.rank = [0] * (n+1)
        # ????????
        self.weight = [0] * (n+1)

    # ??
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            y = self.find(self.par[x])
            # ?????????????????
            self.weight[x] += self.weight[self.par[x]]
            self.par[x] = y
            return y

    # ??
    def union(self, x, y, w):
        rx = self.find(x)
        ry = self.find(y)
        # x????? < y?????
        if self.rank[rx] < self.rank[ry]:
            self.par[rx] = ry
            self.weight[rx] = w - self.weight[x] + self.weight[y]
        # x????? ? y?????
        else:
            self.par[ry] = rx
            self.weight[ry] = -w - self.weight[y] + self.weight[x]
            # ???????????????
            if self.rank[rx] == self.rank[ry]:
                self.rank[rx] += 1

    # ?????????
    def same(self, x, y):
        return self.find(x) == self.find(y)

    # x??y?????
    def diff(self, x, y):
        return self.weight[x] - self.weight[y]


N, M = map(int, input().split())
Un = WeightedUnionFind(N+1)

ans = "Yes"
for _ in range(M):
    l, r, w = map(int, input().split())
    if Un.same(l, r):
        if Un.diff(l, r) != w:
            ans = "No"
            break
    else:
        Un.union(l, r, w)
print(ans)