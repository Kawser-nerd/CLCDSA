N, M = map(int, input().split())

AB = []

for _ in range(M):
    A_i, B_i = map(int, input().split())
    AB.append([A_i, B_i])

class UnionFind():
    def __init__(self, n):
        self.parent = [-1 for _ in range(n)] # ??? -1 * ???
        
    def root(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]
    def size(self, x):
        x = self.root(x)
        return -1 * self.parent[x]
    
    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        x_size = self.size(x)
        y_size = self.size(y)
        if x_size < y_size:
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x
        return True
        
max_inconvenience = N * (N - 1) // 2 
ans = [max_inconvenience]
uf = UnionFind(N)
for bridge in reversed(AB):
    x = uf.root(bridge[0] - 1)
    y = uf.root(bridge[1] - 1)

    if x != y:
        x_size = uf.size(x)
        y_size = uf.size(y)
        ans_tmp = max_inconvenience - x_size * y_size
        max_inconvenience = ans_tmp
        uf.union(x, y)
    else:
        ans_tmp = max_inconvenience
    ans.append(ans_tmp)
    
for a in reversed(ans[:-1]):
    print(a)