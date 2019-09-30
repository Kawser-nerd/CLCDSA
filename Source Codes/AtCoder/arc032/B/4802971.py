class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0]*n
    
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

N, M = map(int, input().split())
road = [[int(_) for _ in input().split()] for _ in range(M)]
uf = UnionFind(N+1)
S = set()

for i in road:
    uf.union(i[0], i[1])

for i in range(1, N+1):
    S.add(uf.find(i))

print(len(S)-1)