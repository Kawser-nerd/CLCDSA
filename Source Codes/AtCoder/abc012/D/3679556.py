from scipy.sparse.csgraph import floyd_warshall
from scipy.sparse.csgraph import dijkstra
n,m=map(int,input().split())
dis=[[float('inf') for i in range(n)]for j in range(n)]
for i in range(n):
    dis[i][i]=0
for i in range(m):
    a,b,t=map(int,input().split())
    dis[a-1][b-1]=t
    dis[b-1][a-1]=t
cost=floyd_warshall(dis)
ans=[max(cost[i])for i in range(n)]
print(int(min(ans)))