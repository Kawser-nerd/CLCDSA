import sys
sys.setrecursionlimit(100000)
class UnionFind:
    def __init__(self, n):
        self.p=[i for i in range(n)]
        self.r=[0 for i in range(n)]
    
    def root(self,x):
        if self.p[x]==x:
            return x
        else:
            self.p[x] = self.root(self.p[x])
            return self.p[x]
    
    def uni(self,x,y):
        x=self.root(x)
        y=self.root(y)
        if(x==y):
            return
        if self.r[x]<self.r[y]:
            self.p[x]=y
        else:
            self.p[y]=x
            if self.r[x]==self.r[y]:
                self.r[x]+=1
    
    def same(self,x,y):
        return self.root(x)==self.root(y)

n,q=map(int,input().split())
uf=UnionFind(2*n)
for i in range(q):
    w,x,y,z=map(int,input().split())
    if w==1:
        if z%2==0:
            uf.uni(x-1,y-1)
            uf.uni(x-1+n,y-1+n)
        else:
            uf.uni(x-1,y-1+n)
            uf.uni(x-1+n,y-1)
    else:
        print('YES'if uf.same(x-1,y-1) else 'NO')