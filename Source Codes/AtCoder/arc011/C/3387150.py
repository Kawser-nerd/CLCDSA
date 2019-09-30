x,y = (i for i in input().split())
n = int(input())
w = tuple([x]+[input() for i in range(n)]+[y])
p,k,inf,ans = [[] for i in range(n+2)],len(x),float("inf"),[y]
def f(a,b):
	c = 0
	for i in range(k):
		if w[a][i]!=w[b][i]:
			if w[a][i+1:]==w[b][i+1:]: c = 1
			break
	return c
for i in range(n+1):
	for j in range(i+1,n+2):
		if f(i,j):
			p[i].append(j)
			p[j].append(i)
from heapq import heappop,heappush
def dijkstra(n,s,adj):
	dis = [[inf,-1] for i in range(n)]
	dis[s][0],q = 0,[[0,s]]
	while q:
		num2,num = heappop(q)
		for i in adj[num]:
			if dis[i][0]>num2+1:
				dis[i][0],dis[i][1] = num2+1,num
				heappush(q,[dis[i][0],i])
	return dis
d = dijkstra(n+2,0,p)
if x==y:
	for i in [0,x,y]: print(i)
elif d[-1][0]==inf: print(-1)
else:
	m,now = d[-1][0],n+1
	for i in range(m):
		now = d[now][1]
		ans.append(w[now])
	print(m-1)
	for i in ans[::-1]: print(i)