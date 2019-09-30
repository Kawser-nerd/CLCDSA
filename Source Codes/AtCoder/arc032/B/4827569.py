n, m = map(int, input().split())
ab=[list(map(int, input().split())) for i in range(m)]
class UnionFind(object):
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]


    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])


    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)
    def count(self):
        ans=0
        for i in range(len(self.parent)):
            if self.parent[i]==i:
                ans+=1
        return ans
u=UnionFind(n)
for abi in ab:
    u.unite(abi[0]-1, abi[1]-1)
print(u.count()-1)