class UFT(object):
    def __init__(self,n):
        self.par={i:i for i in range(1,n+1)}
        self.height={i:0 for i in range(1,n+1)}
    def find(self,n):
        if self.par[n]==n:
            return n
        else:
            self.par[n]=self.find(self.par[n])
            return self.par[n]
    def unite(self,a,b):
        a=self.find(a)
        b=self.find(b)

        if self.height[a]>self.height[b]:
            self.par[b]=a
        else:
            if self.height[a]==self.height[b]:
                self.height[b]+=1
            self.par[a]=b
    def isunite(self,a,b):
        return self.find(a)==self.find(b)

n,m,s=map(int,input().split())
obj=UFT(n)
l=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split())
    if u>v:
        u,v=v,u
    l[u].extend([v])

r=[]
for i in range(n,0,-1):
    for j in l[i]:
        obj.unite(i,j)
    if obj.isunite(s,i):
        r.extend([i])

print(*r[::-1],sep="\n")