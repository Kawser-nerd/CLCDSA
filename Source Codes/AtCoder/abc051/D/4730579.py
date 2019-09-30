from scipy.sparse.csgraph import dijkstra
n, m = map(int, input().split())
edges = [[0]*n for i in range(n)]
query = []
ans = 0
for i in range(m):
    a,b,c = map(int, input().split())
    edges[a-1][b-1] = c
    edges[b-1][a-1] = c
    query.append([a-1, b-1, c])
for a,b,c in query:
    edges[a][b] = 0
    edges[b][a] = 0
    dist_ = dijkstra(edges, directed=False, indices=a)[b]
    if dist_ < c:
        ans += 1
    edges[a][b] = c
    edges[b][a] = c
print(ans)