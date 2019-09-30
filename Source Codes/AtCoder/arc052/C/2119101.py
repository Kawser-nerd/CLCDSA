N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
    c, a, b = map(int, input().split())
    G[a].append((b, c))
    G[b].append((a, c))

from heapq import heappush, heappop
from collections import deque

INF = 10**18

que = [(0, 0)]
cost_m = [INF]*N
b_min = [INF]*N
cost_m[0] = 0
b_min[0] = 0

while que:
    cost, v = heappop(que)
    if cost_m[v] < cost:
        continue

    for w, c in G[v]:
        if c == 0:
            if cost + 1 < cost_m[w]:
                cost_m[w] = cost + 1
                heappush(que, (cost + 1, w))
        else:
            if cost + N < cost_m[w]:
                cost_m[w] = cost + N
                heappush(que, (cost + N, w))
for i in range(N):
    b_min[i] = b = cost_m[i] // N
    cost_m[i] = ((cost_m[i] % N) + b*(b+1)//2)+1

que = [(0, 0, 0)]
dist = [{b_min[i]: cost_m[i]} for i in range(N)]
dist[0][0] = 0
while que:
    cost, v, k = heappop(que)
    if dist[v][k] < cost:
        continue
    b = cost_m[v]
    for w, c in G[v]:
        if c == 0:
            if cost + 1 < dist[w].get(k, cost_m[w]):
                dist[w][k] = cost + 1
                heappush(que, (cost + 1, w, k))
        else:
            if (k+1)*(k+2) > b*(b+1) + 2*(N-1):
                continue
            if cost + k + 1 < dist[w].get(k+1, cost_m[w]):
                dist[w][k+1] = cost + k + 1
                heappush(que, (cost + k + 1, w, k+1))
print(*(min(d.values()) for d in dist), sep='\n')