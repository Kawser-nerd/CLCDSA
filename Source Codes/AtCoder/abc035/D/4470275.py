import heapq

n,m,t = map(int , input().split())
A =  list(map(int, input().split()))
dis = [[] for i in range(n)]
disrev = [[] for i in range(n)]
mindis = [float('inf') for i in range(n)]#???????????????
mindisrev = [float('inf') for i in range(n)]#???????????????
q = [] #priority_queue??????? ???????????

for i in range(m):
    a,b,c = map(int , input().split())
    dis[a-1].append((b-1,c)) 
    disrev[b-1].append((a-1,c))


heapq.heappush(q,(0,0)) #????????

while len(q) != 0: #dijkstra
    cost, town = heapq.heappop(q)
    if mindis[town] < cost: continue
    mindis[town] = cost

    for adj in dis[town]:
        adjtown = adj[0]
        adjcost = adj[1]
        heapq.heappush(q,(adjcost+mindis[town],adjtown))

heapq.heappush(q,(0,0))

while len(q) != 0: #dijkstra
    cost, town = heapq.heappop(q)
    if mindisrev[town] < cost: continue
    mindisrev[town] = cost

    for adj in disrev[town]:
        adjtown = adj[0]
        adjcost = adj[1]
        heapq.heappush(q,(adjcost+mindisrev[town],adjtown))
    
ans = 0

for town in range(n):
    time = mindis[town] + mindisrev[town]
    if t < time : continue
    money = (t - time) * A[town]
    ans = max(ans , money)

print(ans)