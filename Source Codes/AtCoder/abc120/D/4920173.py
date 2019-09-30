class UnionFind(object):
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]
        self.sizes = [1 for _ in range(size)]

    
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
            self.sizes[y] += self.sizes[x]
        else:
            self.parent[y] = x
            self.sizes[x] += self.sizes[y]
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)
    
    def size(self, x):
        return self.sizes[self.find(x)]


N,M = map(int, input().split())

AB = []
for m in range(M):
    AB.append([int(i) for i in input().split()] )

u = UnionFind(N)

com = N*(N-1)//2
ans = [com]


for m in reversed(range(M)):
    a = AB[m][0] -1
    b = AB[m][1] -1
    if u.same(a,b):
        ans.append(com)
    else:
        com -= u.size(a)*u.size(b)
        ans.append(com)
        u.unite(a,b)

for m in reversed(range(M)):
    print(ans[m])