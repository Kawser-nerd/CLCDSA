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
n,m,*t=map(int,open(0).read().split())
u=UnionFind(n+1)
f=defaultdict(list)
e=defaultdict(list)
for l,r,d in zip(t[::3],t[1::3],t[2::3]):
    u.unite(l,r)
    e[l].append((r,d))
for i in range(n+1):
    f[u.root(i)].append(i)
for t in f.values():
    if len(t)<3:continue
    outs=defaultdict(list)
    ins=defaultdict(int)
    for i in t:
        outs[i]=[j for j,v in e[i]]
        for j in outs[i]:
            ins[j]+=1
    q=deque(v1 for v1 in t if ins[v1]==0)
    res=[]
    while q:
        v1=q.popleft()
        res.append(v1)
        for v2 in outs[v1]:
            ins[v2]-=1
            if ins[v2]==0:
                q.append(v2)
    if not res:
        print('No')
        exit()
    c=defaultdict(int)
    for i in res:
        for j,v in e[i]:
            if c[j]and c[j]!=c[i]+v:
                print('No')
                exit()
            c[j]=c[i]+v
print('Yes')