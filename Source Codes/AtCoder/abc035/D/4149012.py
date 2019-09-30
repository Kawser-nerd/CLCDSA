import heapq
n,m,t=map(int,input().split())
A=list(map(int,input().split()))
go=[[] for i in range(n)]
back=[[] for i in range(n)]
for i in range(m):
    a,b,c = map(int, input().split())
    a-=1
    b-=1
    go[a].append([b,c])
    back[b].append([a,c])

def dijkstra(x,route):
    d=[float('inf')]*n
    d[x]=0
    visited={x}
    hq=[(0,x)]
    while hq:
        u=heapq.heappop(hq)[1]
        visited.add(u)
        for node, cost in route[u]:
            if (node not in visited) and d[node]>d[u]+cost:
                d[node]=d[u]+cost
                heapq.heappush(hq,(d[node],node))
    return d

dist_go=dijkstra(0,go)
dist_back=dijkstra(0,back)
ans=0
for i in range(n):
    point=A[i]*(t-dist_go[i]-dist_back[i])
    ans=max(ans,point)
print(ans)