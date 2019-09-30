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

N, K, L = inpl()
ufk = UnionFind(N)
for i in range(K):
    p, q = inpl()
    ufk.union(p-1, q-1)

ufr = UnionFind(N)
for i in range(L):
    r, s = inpl()
    ufr.union(r-1, s-1)

from collections import defaultdict
ans = defaultdict(lambda: 0)
for i in range(N):
    ans[ufk.find(i),ufr.find(i)] +=1
Ans = [0 for _ in range(N)]
for i in range(N):
    Ans[i] = ans[ufk.find(i),ufr.find(i)]
print(*Ans)