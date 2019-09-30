class UnionFind():
    def __init__(self, n):
        self.parent = [-1]*n
    def root(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]
    def union(self, x,y):
        root_x = self.root(x)
        root_y = self.root(y)
        if root_x == root_y:
            return False
        if self.parent[root_x] < self.parent[root_y]:
            self.parent[root_x] += self.parent[root_y]
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] += self.parent[root_x]
            self.parent[root_x] = root_y
        return True

n, m = list(map(int, input().split()))
UF = UnionFind(n)
for i in range(m):
    a, b = list(map(int, input().split()))
    UF.union(a-1, b-1)
print(sum([i<0 for i in UF.parent]) -1)