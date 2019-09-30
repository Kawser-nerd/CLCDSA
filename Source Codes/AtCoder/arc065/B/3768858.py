import sys,collections
from collections import defaultdict
 
class UnionFind():
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * (n)
        
    def printper(self,):
        print(self.par)
 
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
 
def solve():
    N,K,L = map(int,input().split())
    road_uf = UnionFind(N)
    train_uf = UnionFind(N)
    for i in range(K):
        a,b = map(int,input().split())
        road_uf.union(a-1,b-1)
    for i in range(L):
        a,b = map(int,input().split())
        train_uf.union(a-1,b-1)
    ans = defaultdict(lambda: 0)
    for i in range(N):
        ans[road_uf.find(i),train_uf.find(i)] +=1
    Ans = [0 for _ in range(N)]
    for i in range(N):
        Ans[i] = ans[road_uf.find(i),train_uf.find(i)]
    print(*Ans)
    
solve()