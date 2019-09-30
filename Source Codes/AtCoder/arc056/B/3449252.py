import heapq
N,M,S = map(int,input().split())
S -= 1
es = [[] for i in range(N)]
for i in range(M):
    a,b = map(lambda x:int(x)-1,input().split())
    es[a].append(b)
    es[b].append(a)

INF = 1
costs = [INF] * N
costs[S] = -S
hq = [(-S,S)]
heapq.heapify(hq)
while hq:
    c,v = heapq.heappop(hq)
    for to in es[v]:
        if costs[to] < INF: continue
        cost = -min(to, -c)
        costs[to] = cost
        heapq.heappush(hq, (cost,to))

ans = [i+1 for i,c in enumerate(costs) if i == -c]
print(*ans, sep='\n')