# -*- coding: utf-8 -*-
class UnionFindTree():
    def __init__(self, N):
        self.parent = [-1]*(N+1)
        self.rank = [1]*(N+1)
  
    def find(self, i):
        if self.parent[i] == -1:
            group = i
        else:
            group = self.find(self.parent[i]) 
            self.parent[i] = group
        return group
      
    def unite(self, x, y):
        px = self.find(x)
        py = self.find(y)
        if px != py:
            if self.rank[px] == self.rank[py]: # rank is same
                self.rank[px] += 1
            elif self.rank[px] < self.rank[py]:
                px, py = py, px
                
            self.parent[py] = px
    
    def getsize(self, x):
        return self.size[self.find(x)]
    
    def groups(self, index1=True):
        return set([self.find(i) for i in range(0+index1, self.N+index1)])

N, M, S = map(int, input().split())
UFT = UnionFindTree(N)
E = [[] for _ in range(N+1)]
ans = []

for _ in range(M):
    u, v = map(int, input().split())
    if u > v:
        u, v = v, u
    E[u].append(v)

for i in range(N, 0, -1):
    for j in E[i]:
        UFT.unite(i, j)
    if UFT.find(S) == UFT.find(i):
        ans.append(i)

print(*ans[::-1], sep="\n")