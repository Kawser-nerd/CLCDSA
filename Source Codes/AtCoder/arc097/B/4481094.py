n,m=map(int,input().split())
p=list(map(int,input().split()))
l=[]
for i in range(m):
    x,y=map(int,input().split())
    l.append([x,y])

class UnionFind:
    def __init__(self,n):
        self.par=[i for i in range(n)]
        self.rank=[0]*(n)
    def find(self,x):
        if self.par[x]==x:
            return x
        else:
            self.par[x]=self.find(self.par[x])
            return self.par[x]
    def same_check(self,x,y):
        return self.find(x)==self.find(y)
    def union(self,x,y):
        x=self.find(x)
        y=self.find(y)
        if self.rank[x]<self.rank[y]:
            self.par[x]=y
        else:
            self.par[y]=x
            if self.rank[x]==self.rank[y]:
                self.rank[x]+=1

uf=UnionFind(n)

for a,b in l:
    uf.union(a-1,b-1)

num=0
for i in range(n):
    num+=uf.same_check(i,p[i]-1)
print(num)