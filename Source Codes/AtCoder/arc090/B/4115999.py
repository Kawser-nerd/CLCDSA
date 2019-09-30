import sys
sys.setrecursionlimit(100000)
class P_UnionFind:
    def __init__(self, n):
        self.p=[i for i in range(n)]
        self.r=[0 for i in range(n)]
        self.d=[0 for i in range(n)]

    def root(self,x):
        if self.p[x]==x:
            return x
        else:
            tmp = self.root(self.p[x])
            self.d[x] += self.d[self.p[x]]
            self.p[x] = tmp
            return self.p[x]
    
    def weight(self,x):
        self.root(x)
        return self.d[x]

    def diff(self,x,y):
        return self.weight(y)-self.weight(x)

    def uni(self,x,y,w):
        if self.same(x,y) and self.diff(x,y)!=w:
            return False
        w+=self.weight(x)
        w-=self.weight(y)
        x=self.root(x)
        y=self.root(y)
        if(x==y):
            return
        if self.r[x]<self.r[y]:
            self.p[x]=y
            self.d[x]=-w
        else:
            self.p[y]=x
            self.d[y]=w
            if self.r[x]==self.r[y]:
                self.r[x]+=1
    
    def same(self,x,y):
        return self.root(x)==self.root(y)


n,m=map(int,input().split())
uf=P_UnionFind(n)
d=[-1 for i in range(n)]
d[0]=0
data=[]
for i in range(m):
    a,b,c=map(int,input().split())
    if uf.uni(a-1,b-1,c) == False:
        print('No')
        exit()
print('Yes')