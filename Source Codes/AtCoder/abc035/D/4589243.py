import heapq
def dijkstra_heap(s):
    d = [float("inf")]*n
    used = [True]*n
    d[s] = 0
    used[s] = False
    edgelist = []
    for e in edge[s]:
        heapq.heappush(edgelist,e)
    while len(edgelist):
        minedge = heapq.heappop(edgelist)
        if not used[minedge[1]]:
            continue
        v = minedge[1]
        d[v] = minedge[0]
        used[v] = False
        for e in edge[v]:
            if used[e[1]]:
                heapq.heappush(edgelist,[e[0]+d[v],e[1]])
    return d
n,m,t = map(int,input().split()) 
A = list(map(int,input().split()))
edge = [[] for i in range(n)]
P = []
for i in range(m):
    a,b,c = map(int,input().split())
    P.append([a,b,c])
    edge[a-1].append([c,b-1])
D = dijkstra_heap(0)
edge = [[] for i in range(n)]
for i in range(m):
    edge[P[i][1]-1].append([P[i][2],P[i][0]-1])
E = dijkstra_heap(0)
time = [0]*n
score = [0]*n
for i in range(n):
  time[i] = D[i]+E[i]
for i in range(n):
  score[i] = max(0,(t-time[i])*A[i])
print(max(score))