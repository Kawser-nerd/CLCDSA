class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n + 1)]
        self.size = [1] * (n + 1)
        self.rank = [0] * (n + 1)

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
            self.size[y] += self.size[x]
        else:
            self.parent[y] = x
            self.size[x] += self.size[y]
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def check_same(self, x, y):
        return self.find(x) == self.find(y)

    def get_size(self, x):
        return self.size[self.find(x)]


N, M = map(int, input().split())
road = []
r_append = road.append
for i in range(M):
    r_append(tuple(map(int, input().split())))

Q = int(input())
query = []
q_append = query.append
for i in range(Q):
    v, w = map(int, input().split())
    q_append((i, v, w))

road = sorted(road, key=lambda x: x[2], reverse=True)
query = sorted(query, key=lambda x: x[2], reverse=True)

union_find = UnionFind(N)

ans = {}
a, b, y = road[0]
i = 0

u_u = union_find.union
for q in query:
    j, v, w = q
    while i < M and y > w:
        u_u(a, b)
        i += 1
        if i == M:
            break
        a, b, y = road[i]
    ans[j] = union_find.get_size(v)

for i in range(Q):
    print(ans[i])