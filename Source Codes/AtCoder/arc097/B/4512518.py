class UnionFind:
    def __init__(self,N):
        self.table = list(range(N))
        self.rank = [0] * N
        self.size = [1] * N
    
    def find(self,x):
        if self.table[x] == x:
            return x
        else:
            self.table[x] = self.find(self.table[x])
            return self.table[x]
    
    def unite(self,x,y):
        x,y = self.find(x),self.find(y)
        if x == y:
            return
        if self.rank[x] < self.rank[y]:
            self.table[x] = y
            self.size[y] += self.size[x]
        else:
            self.table[y] = x
            self.size[x] += self.size[y]
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
    
    def same(self,x,y):
        return self.find(x) == self.find(y)
    
    def count(self,x):
        return self.size(x)

N,M = map(int,input().split())
P = list(map(int,input().split()))
uf = UnionFind(N)
for _ in range(M):
    x,y = map(int,input().split())
    uf.unite(x-1,y-1)

count = 0
for i in range(N):
    if uf.same(P[i]-1,i):
        count += 1

print(count)