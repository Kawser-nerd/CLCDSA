from collections import*
class UnionFind():
    def __init__(self,size):
        self.table=[-1]*size
    def root(self,x):
        while self.table[x]>=0:
            x=self.table[x]
        return x
    def unite(self,x,y):
        s1=self.root(x)
        s2=self.root(y)
        if s1!=s2:
            if self.table[s1]>self.table[s2]:
                s1,s2=s2,s1
            self.table[s1]+=self.table[s2]
            self.table[s2]=s1
        return
    def same(self,x,y):
        return self.root(x)==self.root(y)
    def size(self,x):
        return -self.table[self.root(x)]
input=open(0).readline
n,k,l=map(int,input().split())
u=UnionFind(n)
v=UnionFind(n)
for _ in range(k):
    p,q=map(int,input().split())
    u.unite(p-1,q-1)
for _ in range(l):
    r,s=map(int,input().split())
    v.unite(r-1,s-1)
d=defaultdict(int)
a=[]
for i in range(n):
    t=(u.root(i),v.root(i))
    d[t]+=1
    a.append(t)
print(*[d[i]for i in a])