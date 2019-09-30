class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n+1)]
        self.rank = [0] * (n+1)
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
    def same_check(self, x, y):
        return self.find(x) == self.find(y)
    
n,m = (int(i) for i in input().split())
uf = UnionFind(n-1)
for i in range(m):
  a,b = (int(i) for i in input().split())
  if a == 1 or b ==n: uf.union(a-1,b-1)

if uf.same_check(0,n-1): print('POSSIBLE')
else:print('IMPOSSIBLE')