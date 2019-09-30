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
n = int(input()) 
a,b = map(int,input().split())
M = int(input())
edge = [[] for i in range(n)]
for i in range(M):
    x,y = map(int,input().split())
    edge[x-1].append([1,y-1])
    edge[y-1].append([1,x-1]) 
L = []
for i in range(n):
    D = dijkstra_heap(i)
    L.append(D)
dp = [0]*n
dp[a-1] = 1
for i in range(n):
    for j in range(n):
        if L[a-1][j] != i:
            continue
        for k in range(n):
            if L[a-1][k] == i+1 and L[j][k] == 1:
                dp[k] = (dp[k]+dp[j])%(10**9+7)
print(dp[b-1])