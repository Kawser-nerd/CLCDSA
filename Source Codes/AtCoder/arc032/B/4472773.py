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
(n,m),*e=[map(int,t.split())for t in open(0).readlines()]
u=UnionFind(n)
for x,y in e:
    u.unite(x-1,y-1)
print(sum(i<0for i in u.table)-1)