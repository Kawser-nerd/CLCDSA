n,m,s = (int(i) for i in input().split())
x = [[] for i in range(n+1)]
for _ in range(m):
	u,v = (int(i) for i in input().split())
	x[u].append(v)
	x[v].append(u)
from heapq import heappop,heappush
cost,vis,q = [i for i in range(n+1)],[True]*(n+1),[(-s,s)]
q,vis[s] = [(-s,s)],False
while q:
	c,p = heappop(q)
	c = -c
	for i in x[p]:
		if vis[i]:
			if cost[i]>c: cost[i] = c
			vis[i] = False
			heappush(q,(-cost[i],i))
for i in range(1,n+1):
	if cost[i]==i: print(i)