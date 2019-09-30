from itertools import combinations
from scipy.sparse.csgraph import floyd_warshall as wf

n,m=map(int,input().split())
inf=float('inf')
edges=[[inf]*n for j in range(n)]
for i in range(n):
  edges[i][i]=0

s=[]
for i in range(m):
  u,v,l=map(int,input().split())
  if u==1:
    s.append((v-1,l))
  elif v==1:
    s.append((u-1,l))
  else:
    edges[u-1][v-1]=l
    edges[v-1][u-1]=l

dist=wf(edges,directed=False)
ans=inf
for u,v in combinations(s,2):
  d=dist[u[0]][v[0]]
  if d!= inf:
    ans=min(ans,u[1]+v[1]+int(d))
if ans==inf:
  print(-1)
else:
  print(ans)