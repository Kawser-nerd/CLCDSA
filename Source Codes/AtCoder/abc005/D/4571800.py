N = int(input())
f = [[0] * (N + 1)] + [[0] + list(map(int, input().split())) for _ in range(N)]
for x in range(N + 1):
    for y in range(1, N + 1):
        f[y][x] += f[y - 1][x]
for y in range(N + 1):
    for x in range(1, N + 1):
        f[y][x] += f[y][x - 1]
M = [0 for _ in range(N * N + 1)]
for y1 in range(1, N + 1):
    for x1 in range(1, N + 1):
        for y2 in range(y1 + 1):
            for x2 in range(x1 + 1):
                s = (y1 - y2) * (x1 - x2)
                M[s] = max(M[s], f[y1][x1] - f[y2][x1] - f[y1][x2] + f[y2][x2])
Q = int(input())
for _ in range(Q):
    ans, L = 0, int(input())
    for i in range(L + 1):
        ans = max(ans, M[i])
    print(ans)