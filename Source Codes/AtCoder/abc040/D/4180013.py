class UnionFind:
    def __init__(self, n):
        self.rank = [0] * n
        self.parent = [i for i in range(n)]
        self.num = [1] * n

    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]

    def merge(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
            self.num[y] += self.num[x]
        elif self.rank[x] > self.rank[y]:
            self.parent[y] = x
            self.num[x] += self.num[y]
        else:
            self.parent[x] = y
            self.rank[y] += 1
            self.num[y] += self.num[x]

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
road = []
for i in range(m):
    a, b, y = map(int, input().split())
    road.append((a-1, b-1, y))
q = int(input())
query = []
for i in range(q):
    v, w = map(int, input().split())
    query.append((v-1, w, i))

road.sort(key=lambda x: x[2], reverse=True)
query.sort(key=lambda x: x[1], reverse=True)

uf = UnionFind(n)


ans = []
j = 0
for v, w, i in query:
    while j < m and road[j][2] > w:
        uf.merge(road[j][0], road[j][1])
        j += 1
    ans.append((uf.num[uf.find(v)], i))

ans.sort(key=lambda x: x[1])
for i in range(q):
    print(ans[i][0])