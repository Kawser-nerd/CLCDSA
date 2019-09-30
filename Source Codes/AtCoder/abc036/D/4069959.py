import sys
from collections import defaultdict as dd
sys.setrecursionlimit(1000000)

d=dd(list)
mod=1000000007

n=int(input())
for _ in range(n-1):
  a,b=map(int,input().split())
  d[a].append(b)
  d[b].append(a)

d=dict(d)
f=[None]*(n+1)
g=[None]*(n+1)

def dfs(p,x):
  for i in d[x]:
    if i!=p:
      dfs(x,i)
  f[x],g[x]=1,1
  
  for i in d[x]:
    if i!=p:
      g[x]*=f[i]
      g[x]%=mod
      f[x]*=g[i]
      f[x]%=mod
  f[x]+=g[x]
  f[x]%=mod

dfs(-1,1)
print(f[1])