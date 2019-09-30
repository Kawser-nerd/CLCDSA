def inpl():
    return list(map(int, input().split()))


N, A = inpl()
X = inpl()
maxX = max(X)

dp = [[[0 for _ in range(N * maxX + 1)] for j in range(i + 1)]
      for i in range(51)]

dp[0][0][0] = 1
for i in range(N):
    x = X[i - 1]
    for j in range(i + 1):
        for k in range(N * maxX + 1):
            # print(i, j, k)
            if dp[i][j][k] == 0:
                continue
            dp[i + 1][j][k] += dp[i][j][k]
            dp[i + 1][j + 1][k + x] += dp[i][j][k]

ans = 0
for j in range(1, N + 1):
    if j * A > N * maxX:
        continue
    ans += dp[N][j][j * A]
print(ans)