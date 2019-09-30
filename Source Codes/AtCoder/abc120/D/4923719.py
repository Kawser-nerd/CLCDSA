def main():

    N, M = map(int, input().split())
    bridges = [None] * M
    for m in range(M):
        bridges[m] = tuple(map(int, input().split()))

    tree = UnionFind(N)
    increments = [0] * M

    for m in range(M)[::-1]:

        if tree.is_same(*bridges[m]):
            continue

        increments[m] += tree.get_size(bridges[m][0]) * tree.get_size(bridges[m][1])
        tree.unite(*bridges[m])

    cumsum = 0
    for i in increments:
        cumsum += i
        print(cumsum)


class UnionFind:

    def __init__(self, n):
        self.par = list(range(n+1))
        self.rank = [0] * (n+1)
        self.size = [1] * (n+1)

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] > self.rank[y]:
            self.par[y] = x
            self.size[x] += self.size[y]
        elif self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.size[y] += self.size[x]
        else:
            self.par[x] = y
            self.size[y] += self.size[x]
            self.rank[y] += 1

    def get_size(self, x):
        return self.size[self.find(x)]

    def is_same(self, x, y):
        return self.find(x) == self.find(y)

main()