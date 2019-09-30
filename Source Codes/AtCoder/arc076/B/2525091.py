class UnionFind(object):
  def __init__(self,n):
    self.table=[-1]*n
 
  def find(self,x):
    parent=self.table[x]
    if parent<0:
      return x
    else:
      root=self.find(parent)
      self.table[x]=root
      return root
 
  def union(self,a,b):
    root1=self.find(a)
    root2=self.find(b)
    if root1 != root2:
      if self.table[root1] != self.table[root2]:
        if self.table[root1] < self.table[root2]:
          self.table[root2]=root1
        else:
          self.table[root1]=root2
      else:
        self.table[root1]+=(-1)
        self.table[root2]=root1

N=int(input())
x=[]
y=[]
M=[]
for i in range(N):
  X,Y=map(int,input().split())
  x.append((i,X))
  y.append((i,Y))

x=sorted(x,key=lambda x:x[1])
y=sorted(y,key=lambda y:y[1])

for i in range(N-1):
  a,b=x[i]
  c,d=y[i]
  e,f=x[i+1]
  g,h=y[i+1]
  M.append((f-b,a,e))
  M.append((h-d,c,g))
  
uf=UnionFind(N)
ans=0

for v,s,t in sorted(M,key=lambda x:x[0]):
  if uf.find(s)!=uf.find(t):
    uf.union(s,t)
    ans+=v

print(ans)