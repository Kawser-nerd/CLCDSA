import heapq
class edge:
    def __init__(self,to,cost):
        self.to=to
        self.cost=cost

N,W=map(int,input().split())
G=[list() for i in range(10)]

for i in range(10):
    tmp=list(map(int,input().split()))
    for j in range(10):
        if(i!=j):
            G[i].append(edge(j,tmp[j]))
            #G[j].append(edge(i,tmp[j])) #??????????


ans=[0 for _ in range(10)]
for j in range(N):
    tmp=list(map(int,input().split()))
    for i in tmp:
        if(i!=-1):
            ans[i]+=1


def dijkstra(o):
    d=[float('inf') for i in range(10)]
    d[o]=0
    hq=[]
    prev=[[] for i in range(10)]
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

s=0
for i in range(len(ans)):
    if(ans[i]!=0):
        s+=dijkstra(i)[0][1]*ans[i]
print(s)