import heapq
from math import hypot

N = int(input())
src = [tuple(map(int,input().split())) for i in range(N)]

INF = float('inf')
dist = [INF] * N
dist[0] = 0
hq = [(0,0)]
heapq.heapify(hq)
visited = [0] * N
nodes = 0

while hq:
    d,i = heapq.heappop(hq)
    if visited[i]: continue
    visited[i] = 1
    nodes += 1
    if nodes == N: break
    xi,yi,ti,ri = src[i]
    for j,(xj,yj,tj,rj) in enumerate(src):
        if i==j: continue
        dij = hypot(xi-xj, yi-yj) / min(ti,rj)
        if d + dij >= dist[j]: continue
        dist[j] = d + dij
        heapq.heappush(hq, (dist[j], j))

ans = 0
dist.sort(reverse=True)
for i,d in enumerate(dist[:-1]):
    ans = max(ans, d+i)
print(ans)