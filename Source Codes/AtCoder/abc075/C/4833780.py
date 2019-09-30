class UnionFind(object):
    def __init__(self, num):
        self.parent = [-1 for i in range(num + 1)]

    def find(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return

        if self.size(x) > self.size(y):
            self.parent[x] += self.parent[y]
            self.parent[y] = x
        else:
            self.parent[y] += self.parent[x]
            self.parent[x] = y

    def size(self, x):
        return -self.parent[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

n, m = map(int, input().split())
lis = []
count = 0
for i in range(m):
    lis.append(list(map(int, input().split())))
for i in range(m):
    u = UnionFind(n)
    for j in range(m):
        if i == j:
            continue
        u.unite(lis[j][0], lis[j][1])
    if not u.same(lis[i][0], lis[i][1]):
        count += 1
print(count)