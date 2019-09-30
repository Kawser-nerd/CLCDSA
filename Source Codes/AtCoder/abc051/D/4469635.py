import heapq
n,m=map(int,input().split())
edges=[[] for _ in range(n)]
ABC=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    a,b=a-1,b-1
    edges[a].append((b,c))
    edges[b].append((a,c))
    ABC.append([a,b,c])

def dijkstra(x,route):
    d=[float('inf')]*n
    d[x]=0
    visited={x}
    hq=[(0,x)]
    while hq:
        u=heapq.heappop(hq)[1]
        visited.add(u)
        for node,cost in route[u]:
            if (node not in visited) and d[node]>d[u]+cost:
                d[node]=d[u]+cost
                heapq.heappush(hq,(d[node],node))
    return d

dist=[[] for _ in range(n)]
for i in range(n):
    dist[i]=dijkstra(i,edges)
ans=0
for a,b,c in ABC:
    if dist[a][b]!=c:
        ans+=1
print(ans)