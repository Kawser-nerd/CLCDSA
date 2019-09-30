from scipy.sparse.csgraph import dijkstra

n, m = map(int, input().split())
d = [[float('inf') for i in range(n)] for j in range(n)]

for i in range(n):
    d[i][i] = 0


for _ in range(m):
    a, b, t = map(int, input().split())
    d[a-1][b-1] = t
    d[b-1][a-1] = t

cost = dijkstra(d)

ans = [max(cost[i]) for i in range(n)]

print(int(min(ans)))