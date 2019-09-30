import heapq

def dijkstra(graph, node, start):
    dist = [float("inf") for _ in range(node)]

    dist[start] = 0
    q = []
    heapq.heappush(q, (0, start))

    while q:
        cost, cur_node = heapq.heappop(q)

        if dist[cur_node] < cost:
            continue

        for nex_cost, nex_node in graph[cur_node]:
            dist_cand = dist[cur_node] + nex_cost
            if dist_cand < dist[nex_node]:
                dist[nex_node] = dist_cand
                heapq.heappush(q, (dist[nex_node], nex_node))

    return dist

n, m, t = map(int, input().split())
a = list(map(int, input().split()))
g = [[] for _ in range(n)]
r = [[] for _ in range(n)]
for i in range(m):
    x, y, z = map(int, input().split())
    x -= 1
    y -= 1
    g[x].append((z, y))
    r[y].append((z, x))
go = dijkstra(g, n, 0)
ret = dijkstra(r, n, 0)
ans = a[0] * t
for i in range(1, n):
    temp = go[i] + ret[i]
    if temp < t:
        ans = max(ans, a[i] * (t - temp))

print(ans)