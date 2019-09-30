import heapq
def dijkstra_heap(s):
    d = [float("inf")]*n
    used = [True] * n
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
edge = [[] for i in range(n)]
for i in range(n-1):
    x,y,z = map(int,input().split())
    edge[x-1].append([z,y-1])
    edge[y-1].append([z,x-1])
Q,K = map(int,input().split())
L = dijkstra_heap(K-1)
query = []
for i in range(Q):
  query.append(list(map(int,input().split())))
for i in range(Q):
  print(L[query[i][0]-1]+L[query[i][1]-1])