from heapq import heappush, heappop
def dijkstra(num, start):
    dist = [float("inf") for i in range(num)]
    dist[start] = 0
    q = [[dist[start], start]]
    while q:
        du, u = heappop(q)
        for j, k in adj[u]:
            if dist[j] > du + k:
                dist[j] = du + k
                heappush(q, [dist[j], j])
    return dist
n = int(input())
adj = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append([b,1])
    adj[b].append([a,1])
di = dijkstra(n, 0)
ma = 0
for i in range(n):
    if di[i] > di[ma]:
        ma = i
dis = dijkstra(n,ma)
mi = 0
for i in range(n):
    if dis[i] > dis[mi]:
        mi = i
print(ma+1,mi+1)