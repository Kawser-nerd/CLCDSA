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


N, M = map(int, input().split())
road = [[int(_) for _ in input().split()] for _ in range(M)]
Q = int(input())
people = [[int(_) for _ in input().split()] for _ in range(Q)]
p_data = []
uf = UnionFind(N+1)

for i, j in enumerate(people):
    p_data.append([i, j[0], j[1], 0])

road = sorted(road, key=lambda x: -x[2])
p_data = sorted(p_data, key=lambda x: -x[2])
roadindex = 0

for i in p_data:
    for j in range(roadindex, M):
        if road[j][2] <= i[2]:
            break
        else:
            uf.unite(road[j][0], road[j][1])
            roadindex += 1
    
    i[3] = uf.tree_size(i[1])

p_data = sorted(p_data, key=lambda x: x[0])
for i in p_data:
    print(i[3])