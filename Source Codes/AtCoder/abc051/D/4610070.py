import heapq
class edge:
    def __init__(self,to,cost):
        self.to=to
        self.cost=cost

N,W=map(int,input().split())
G=[list() for i in range(N)]
for i in range(W):
    a,b,c=map(int,input().split())
    G[a-1].append(edge(b-1,c))
    G[b-1].append(edge(a-1,c)) #??????????

def dijkstra(o):
    d=[float('inf') for i in range(N)]
    d[o]=0
    hq=[]
    prev=[[] for i in range(N)]
    heapq.heappush(hq,(0,o))
    while hq:
        p=heapq.heappop(hq)
        v=p[1]
        if(d[v]<p[0]):
            continue
        for i in G[v]:
            if(d[i.to]>d[v]+i.cost):
                d[i.to]=d[v]+i.cost
                prev[i.to]=prev[v]+[str(sorted([v,i.to]))]
                heapq.heappush(hq,(d[i.to],i.to))
    return d,prev


ans=set()
for i in range(N):
    tmp=dijkstra(i)[1]
    for j in tmp:
        if(j):
            ans.add(str(j[0]))
print(W-len(ans))