from heapq import *
n,m,s=map(int, input().split())
s-=1
g=[[] for i in range(n)]
for i in range(m):
 u,v=map(int, input().split())
 u-=1; v-=1;
 g[u].append(v)
 g[v].append(u)
h=[]
ds=[0]*n
heappush(h, (-s,s))
ds[s]=s
while len(h):
 p,v=heappop(h)
 p=-p
 if v<p or ds[v]>p:continue
 for to in g[v]:
  np=min(p,to)
  if ds[to]>=np:continue
  ds[to]=np
  heappush(h, (-np,to))
for x in [i+1 for i in range(n) if ds[i]>=i] : print(x)