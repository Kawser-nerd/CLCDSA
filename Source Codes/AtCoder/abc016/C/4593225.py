N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(M)]

dist = [[10 ** 5 for _ in range(N)] for _ in range(N)]
res = [0 for _ in range(N)]

def warshall_floyd(d, V): #d[i][j]?2???i, j??????????, V????
    for k in range(V):
        for i in range(V):
            for j in range(V):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])        
    return d

for i in range(M):
    A[i][0] -= 1
    A[i][1] -= 1
    
for i in range(N):
    for j in range(N):
        if i == j:
            dist[i][j] = 0

for i in range(M):
    dist[A[i][0]][A[i][1]] = 1
    dist[A[i][1]][A[i][0]] = 1
        
distance = warshall_floyd(dist, N)

for i in range(N):
    for j in range(N):
        if distance[i][j] == 2:
            res[i] += 1
            
for i in range(N):
    print(res[i])