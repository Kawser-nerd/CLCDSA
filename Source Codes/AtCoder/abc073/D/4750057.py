from scipy.sparse.csgraph import dijkstra

n, m, r = map(int,input().split())
rs = list(map(int, input().split()))
edge = [[0]*n for i in range(n)]
for i in range(m):
    a, b, c = list(map(int, input().split()))
    a, b = a-1, b-1
    edge[a][b] = c
    edge[b][a] = c
dist = dijkstra(edge, directed=False, indices=[i for i in range(n)])

from itertools import permutations
ans = float("inf")
    
for v in permutations(rs, len(rs)):
    dist_tmp = 0
    for i in range(r-1):
        dist_tmp += dist[v[i]-1][v[i+1]-1]
    ans = min(ans, int(dist_tmp))
print(ans)