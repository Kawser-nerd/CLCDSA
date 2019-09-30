N = int(input())
dp = [[[[0 for i in range(0, 4)] for j in range(0, 4)] for k in range(0, 4)] for l in range(0, 101)]

dp[0][3][3][3] = 1
for n in range(0, 100):
    for i in range(0, 4):
        for j in range(0, 4):
            for k in range(0, 4):
                for l in range(0, 4):
                    if dp[n][i][j][k] == 0:
                        continue

                    if (j == 0 and k == 2 and l == 1
                        or j == 0 and k == 1 and l == 2
                        or j == 2 and k == 0 and l == 1
                        or i == 0 and k == 2 and l == 1
                        or i == 0 and j == 2 and l == 1):
                        continue
                    dp[n+1][j][k][l] += dp[n][i][j][k]

ans = 0
for i in range(0, 4):
    for j in range(0, 4):
        for k in range(0, 4):
            ans += dp[N][i][j][k]
            ans %= pow(10, 9) + 7
print(ans)