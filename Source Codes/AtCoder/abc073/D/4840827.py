from itertools import permutations
N, M, R = map(int, input().split())
r = list(map(int, input().split()))
E = [list(map(int, input().split())) for _ in range(M)]
INF = 10 ** 9
d = [[INF for j in range(N)] for i in range(N)]
for i, j, c in E:
    d[i - 1][j - 1] = c
    d[j - 1][i - 1] = c
for k in range(N):
    for i in range(N - 1):
        for j in range(i, N):
            dk = d[i][k] + d[k][j]
            if d[i][j] > dk:
                d[i][j] = dk
                d[j][i] = dk
ans = 10 ** 9
for ri in permutations(r):
    x = 0
    for i in range(R - 1):
        x += d[ri[i] - 1][ri[i + 1] - 1]
    if ans > x:
        ans = x
print(ans)