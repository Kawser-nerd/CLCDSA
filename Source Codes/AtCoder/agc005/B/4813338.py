import sys
input = sys.stdin.readline

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0]*n
        self.size = [1]*n

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x != y:
            if self.rank[x] < self.rank[y]:
                self.par[x] = y
                self.size[y] += self.size[x]
            else:
                self.par[y] = x
                self.size[x] += self.size[y]

            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    def tree_size(self, x):
        return self.size[self.find(x)]


N = int(input())
a = [-1] + [int(_) for _ in input().split()] + [-1]
uf = UnionFind(N+1)
place = [-1]*(N+1)
ans = 0

for i in range(1, N+1):
    place[a[i]] = i

for i in range(N, 0, -1):
    left = right = 0
    if a[place[i]] < a[place[i]-1]:
        left = uf.tree_size(uf.find(a[place[i]-1]))
        uf.unite(a[place[i]], a[place[i]-1])
    
    if a[place[i]] < a[place[i]+1]:
        right = uf.tree_size(uf.find(a[place[i]+1]))
        uf.unite(a[place[i]], a[place[i]+1])
    
    ans += (left+1)*(right+1)*a[place[i]]

print(ans)