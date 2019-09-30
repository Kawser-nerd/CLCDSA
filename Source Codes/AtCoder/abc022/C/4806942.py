from scipy.sparse.csgraph import floyd_warshall as wf

n,m= map(int, input().split())
UVL = [list(map(int,input().split())) for i in range(m)]
INF = float('inf')

d = [[INF]*n for i in range(n)]
for i in range(n):
    d[i][i] = 0
for u,v,l in UVL:
    if u != 1 and v != 1:
        d[u-1][v-1] = l
        d[v-1][u-1] = l

d = wf(d)
                    
start= []
for i in range(m):
    if UVL[i][0] == 1:
        start.append(UVL[i])

ans = INF
for i in start:
    for j in start:
        if i != j and d[i[1]-1][j[1]-1] != INF:
            tmp = i[2]+j[2]+d[i[1]-1][j[1]-1]
            ans = min(ans, tmp)
        
if ans == INF:
    print(-1)
else:
    print(int(ans))