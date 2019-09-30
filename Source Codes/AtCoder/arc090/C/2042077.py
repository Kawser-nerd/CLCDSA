from functools import reduce
import heapq as hq
from sys import stdin
 
MOD = 10**9+7
N,M = map(int,stdin.readline().split())
S,T = map(int,stdin.readline().split())
S,T = S-1,T-1

inf = float('inf')
 
E = [[] for _ in range(N)]
lines = stdin.readlines()
for line in lines:
  u,v,d = map(int,line.split())
  E[u-1].append((v-1,d))
  E[v-1].append((u-1,d))
 
dS = [inf]*N
dT = [inf]*N
 
Q = [(0,S,False),(0,T,True)]

D = inf

 
while Q:
  d,v,f = hq.heappop(Q)
  if d*2 > D:
    break

  dM = dT if f else dS
  dN = dS if f else dT
  if dM[v] > d:
    dM[v] = d
    for u,dd in E[v]:
      if dM[u] > d and (d+dd)*2 <= D:
        hq.heappush(Q,(d+dd,u,f))
   
  D = min(dN[v]+d,D)
 
del Q


def helper(start,dist):
  cnts = [0]*N
  cnts[start] = 1

  for d,v in sorted((d,v) for v,d in enumerate(dist) if d != inf):
    c = cnts[v]
    for u,dd in E[v]:
      if dd+d == dist[u]:
        cnts[u] = (cnts[u]+c) % MOD

  return cnts

Sn = helper(S,dS)
Tn = helper(T,dT)


def it():
  for v in range(N):
    if dS[v] != inf:
      ds = dS[v]
      if dT[v] == ds and ds*2 == D:
        yield Sn[v]*Tn[v] % MOD
      else:
        for u,d in E[v]:
          if abs(dT[u]-ds) < d and ds+d+dT[u] == D:
            yield Sn[v]*Tn[u] % MOD


X = tuple(it())
 
total = reduce(lambda a,b:(a+b)%MOD, X,0)
total = total*total % MOD
 
sub = reduce(lambda a,b:(a+b)%MOD, map(lambda x: x*x % MOD, X),0)

print((total-sub)%MOD)