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
        return self.size[x]

N,Q = map(int,input().split())
uf = UnionFind(N*2)
ans = []
for _ in range(Q):
    w,x,y,z = map(int,input().split())
    if w == 1:
        if z%2 == 0:
            uf.unite(x-1,y-1)
            uf.unite(x-1+N,y-1+N)
        else:
            uf.unite(x-1,y-1+N)
            uf.unite(x-1+N,y-1)
    else:
        ans.append('YES' if uf.same(x-1,y-1) else 'NO')
for a in ans:
    print(a)