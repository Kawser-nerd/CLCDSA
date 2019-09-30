n, m = map(int, input().split())
ab = [list(map(int, input().split())) for i in range(m)]
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
def C(x):
    U=UnionFind(n)
    for i in range(m):
        if i==x :
            continue
        U.unite(ab[i][0]-1, ab[i][1]-1)
    for i in range(n):
        for j in range(n):
            if not U.same(i, j):
                return False
    return True
ans=0
for y in range(m):
    if not C(y):
        ans+=1
print(ans)