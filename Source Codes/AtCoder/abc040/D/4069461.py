N, M = map(int, input().split())
Roads = []
for i in range(M):
    a, b, y = map(int, input().split())
    a, b = a - 1, b - 1
    Roads.append([a, b, y])
Roads.sort(key=lambda x: x[2])

Q = int(input())
Info = []
for i in range(Q):
    v, w = map(int, input().split())
    v -= 1
    Info.append([i, v, w])
Info.sort(key=lambda x: x[2], reverse=True)


class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * n
        self.size = [1] * n

    # ??
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    # ??
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.size[y] += self.size[x]
            self.size[x] = 0
        else:
            self.par[y] = x
            self.size[x] += self.size[y]
            self.size[y] = 0
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    # ???????????
    def same(self, x, y):
        return self.find(x) == self.find(y)

    # ????????????????
    def all_find(self):
        for n in range(len(self.par)):
            self.find(n)


UF = UnionFind(N)
ans = [0] * Q

for i, v, w in Info:
    while Roads:
        a, b, y = Roads[-1]
        if y > w:
            UF.union(a, b)
            Roads.pop()
        else:
            break
    ans[i] = UF.size[UF.find(v)]

for a in ans:
    print(a)