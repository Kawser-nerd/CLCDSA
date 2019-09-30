from itertools import product
from collections import defaultdict as dd
 
class UnionFind(object):
  def __init__(self,n):
    self.parent={i:i for i in range(1,n+1)}
    self.size={i:1 for i in range(1,n+1)}
  def find(self,a):
    if self.parent[a]!=a:
      self.parent[a]=self.find(self.parent[a])
    return self.parent[a]
  def unite(self,a,b):
    a=self.find(a)
    b=self.find(b)
    if a==b:return
    if self.size[a]>self.size[b]:
      self.size[a]+=self.size[b]
      self.parent[b]=a
    else:
      self.size[b]+=self.size[a]
      self.parent[a]=b
  def isunited(self,a,b):
    return self.find(a)==self.find(b)

n,m=map(int,input().split())
uft=UnionFind(n)

roads=sorted([tuple(map(int,input().split())) for _ in range(m)],key=lambda x:-x[2]) #a,b,y

q=int(input())
queue=sorted([tuple(map(int,input().split()))+(i,) for i in range(q)],key=lambda x:-x[1]) #v,w 

ans=[0]*q
pos=0
for v,w,i in queue:
  while pos<m and roads[pos][2]>w:
    a,b,_=roads[pos]
    uft.unite(a,b)
    pos+=1
  ans[i]=uft.size[uft.find(v)]

print(*ans,sep="\n")