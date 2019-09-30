from scipy.sparse.csgraph import floyd_warshall as wf

n, m = map(int, input().split())
uvl = [list(map(int, input().split())) for _ in range(m)]
INF = float('inf')

# initialization
d = [[INF] * n for _ in range(n)]
for i in range(n):
    d[i][i] = 0
for u, v, l in uvl:
    if u != 1 and v != 1:
        d[u - 1][v - 1] = l
        d[v - 1][u - 1] = l
d = wf(d)

start = []
for i in range(m):
    if uvl[i][0] == 1:
        start.append(uvl[i])
ans = INF
for i in start:
    for j in start:
        if i != j and d[i[1] - 1][j[1] - 1] != INF:
            tmp = i[2] + j[2] + d[i[1] - 1][j[1] - 1]
            ans = min(ans, tmp)
print(int(ans) if ans != INF else -1)