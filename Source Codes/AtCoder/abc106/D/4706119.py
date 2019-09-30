N, M, Q = map(int, input().split())

coordinate = [[0] * N for _ in range(N)]
for _ in range(M):
    l, r = map(int, input().split())
    l, r = l - 1, r - 1
    coordinate[l][r] += 1

acc = [[0] * (N + 1) for _ in range(N + 1)]
for i in range(N):
    for j in range(N):
        acc[i + 1][j + 1] = acc[i][j + 1] + acc[i + 1][j] - acc[i][j] + coordinate[i][j]

for _ in range(Q):
    p, q = map(int, input().split())
    p, q = p - 1, q - 1
    ans = acc[N][q + 1] - acc[p][q + 1]
    print(ans)