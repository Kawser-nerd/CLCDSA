from scipy.sparse.csgraph import floyd_warshall
N, M = map(int, input().split())
g = [[0 for j in range(N)] for i in range(N)]
for i in range(M):
    a, b, t = map(int, input().split())
    g[a-1][b-1] = t
    g[b-1][a-1] = t
print(min([int(max(l)) for l in floyd_warshall(g)]))