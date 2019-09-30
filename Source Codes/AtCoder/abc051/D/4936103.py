N, M = map(int, input().split())

A = []
B = []
C = []
for i in range(M):
    a, b, c = map(int, input().split())
    A.append(a-1)
    B.append(b-1)
    C.append(c)

INF = 10**9
# dist is minimal distance between node i and node j
dist = [[INF if i != j else 0 for i in range(N)] for j in range(N)]

# calculate minimal distance of all nodes combination
for i in range(M):
    dist[A[i]][B[i]] = min(dist[A[i]][B[i]], C[i])
    dist[B[i]][A[i]] = min(dist[B[i]][A[i]], C[i])

for k in range(N):
    for i in range(N):
        for j in range(N):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

ans = M
for i in range(M):
    # isShortest = False
    for j in range(N):
        if dist[j][A[i]] + C[i] == dist[j][B[i]]:
            ans = ans - 1
            break

print(ans)