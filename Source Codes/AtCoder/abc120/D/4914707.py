class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n+1)]
        self.rank = [0]*(n+1)
        self.nsize = [1]*(n+1)
    
    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    
    def union(self,x,y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
            self.nsize[y] += self.nsize[x]
        else:
            if x != y:
                self.nsize[x] += self.nsize[y]
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1
    
    def length(self, x):
        t = self.find(x)
        return self.nsize[t]
    
    def same_check(self, x, y):
        return self.find(x) == self.find(y)


n, m = map(int,input().split())
uf = UnionFind(n)
N = n*(n-1)//2
ans = [N]
bridge = []
for i in range(m):
    t1, t2 = map(int,input().split())
    bridge.append([t1,t2])
    
for x,y in bridge[::-1]:
    if uf.find(x) != uf.find(y):
        ans.append(N - uf.length(x)*uf.length(y))
        N -= uf.length(x)*uf.length(y)
        uf.union(x,y)
    else:
        ans.append(N)
for i in ans[0:-1][::-1]:
    print(i)