inpl = lambda: list(map(int,input().split()))

class UnionFind:
    def __init__(self, N=0):
        if N > 0:
            self.parent = [-1]*N
        else:
            self.parent = defaultdict(lambda: -1)

    def root(self,n):
        if self.parent[n] < 0:
            return n
        else:
            m = self.root(self.parent[n])
            self.parent[n] = m
            return m

    def merge(self,m,n):
        rm = self.root(m)
        rn = self.root(n)
        if rm != rn:
            if -self.parent[rm] < -self.parent[rn]:
                rm, rn = rn, rm
            self.parent[rm], self.parent[rn] = self.parent[rm]+self.parent[rn], rm

    def size(self,n):
        return -self.parent[self.root(n)]
    
    def issame(self, m, n):
        return self.root(m) == self.root(n)

N, M = inpl()
roads = []
for i in range(1,N+1):
    c = int(input())
    roads.append([0,i,c])
for _ in range(M):
    roads.append(inpl())

roads.sort(key=lambda x: x[2])
uf = UnionFind(N+1)
g = N+1
ans = 0
for i in range(M+N):
    r1 = uf.root(roads[i][0])
    r2 = uf.root(roads[i][1])
    if r1 == r2:
        continue
    else:
        ans += roads[i][2]
        uf.merge(r1,r2)
        g -= 1
        if g == 1:
            break
print(ans)