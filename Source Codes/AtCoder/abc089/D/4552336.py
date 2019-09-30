H, W, D = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
Q = int(input())
L, R = zip(*(map(int, input().split()) for _ in range(Q)))
p = {A[i][j]: (i, j) for i in range(H) for j in range(W)}
dp = [0 for _ in range(H * W + 1)]
for x in range(D + 1, H * W + 1):
    y = x - D
    dp[x] = dp[y] + abs(p[x][0] - p[y][0]) + abs(p[x][1] - p[y][1])
ans = '\n'.join(str(dp[r] - dp[l]) for l, r in zip(L, R))
print(ans)