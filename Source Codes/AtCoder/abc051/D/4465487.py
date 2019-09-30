def warshall_floyd(d, V, M): #d[i][j]?2???i, j??????????, V????
    for k in range(V):
        for i in range(V):
            for j in range(V):
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j])
                
    return d
    
N, M = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(M)]
dist = [[10 ** 5 for i in range(N)] for i in range(N)]

for l in L:
    l[0] -= 1
    l[1] -= 1
      
for i in range(M):
    dist[L[i][0]][L[i][1]] = L[i][2]
    dist[L[i][1]][L[i][0]] = L[i][2]

dist = warshall_floyd(dist, N, M)

res = 0

for i in range(M):
    if dist[L[i][0]][L[i][1]] != L[i][2]:
        res += 1
            
print(res)