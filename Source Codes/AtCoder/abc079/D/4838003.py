import collections
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



h, w = map(int, input().split())
c = [list(map(int, input().split())) for i in range(10)]
adj = [[] for _ in range(10)]
for i in range(10):
    for j in range(10):
        c_ = c[i][j]
        adj[i].append((c_, j))
a = []
for i in range(h):
    A = list(map(int, input().split()))
    for j in A:
        a.append(j)
ac = collections.Counter(a)
ans = 0
for i in ac:
    if i != -1:
        ans += dijkstra(adj, 10, i)[1] * ac[i]
print(ans)