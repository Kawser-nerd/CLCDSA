from scipy.sparse.csgraph import floyd_warshall
n,m = map(int, input().split())
dist = [[float("inf")]*n for i in range(n)]
takahashi = {}
for i in range(n):
    dist[i][i] = 0
for i in range(m):
    a,b, l = map(int,input().split())
    a -= 1
    b -= 1
    if a == 0:
        takahashi[b] = l
    else:
        dist[a][b] = l
        dist[b][a] = l
dist = floyd_warshall(dist, directed=False)

can_go = list(takahashi.keys())
k = len(can_go)
ans = float("inf")
for i in range(k):
    for j in range(i+1,k):
        ind_i = can_go[i]
        ind_j = can_go[j]
        ans = min(ans, takahashi[ind_i]+takahashi[ind_j]+dist[ind_i][ind_j])
if ans == float("inf"):
    print(-1)
else:
    print(int(ans))