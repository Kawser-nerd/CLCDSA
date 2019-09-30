def inpl(): return [int(i) for i in input().split()]
class UnionFind():
    def __init__(self, num):
        self.par = [-1 for _ in range(num)]
    
    def find(self, x):
        if self.par[x] < 0:
            return x
        else:
            x = self.par[x]
            return self.find(x)
    
    def union(self, x, y):
        rx = self.find(x)
        ry = self.find(y)
        if rx != ry:
            if self.par[rx] < self.par[ry]:
                self.par[ry] = rx
            if self.par[rx] > self.par[ry]:
                self.par[rx] = ry
            else:
                self.par[rx] -= 1
                self.par[ry] = rx
        return

N = int(input())
V = [0 for _ in range(N)]
Edge = []
for i in range(N):
    x, y = inpl()
    V[i] = (x, y, i)
V = sorted(V, key = lambda x: x[0])
for i in range(N-1):
    Edge.append((V[i+1][0]-V[i][0],V[i+1][2],V[i][2]))
V = sorted(V, key = lambda x: x[1])
for i in range(N-1):
    Edge.append((V[i+1][1]-V[i][1],V[i+1][2],V[i][2]))

Edge = sorted(Edge, key = lambda x: -x[0])
U = UnionFind(N)
ctr = 0
ans = 0
while ctr != N-1:
    c,i,j = Edge.pop()
    if U.find(i) != U.find(j):
        U.union(i,j)
        ans += c
        ctr += 1
print(ans)