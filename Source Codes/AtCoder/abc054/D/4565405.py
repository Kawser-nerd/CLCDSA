n, ma, mb = map(int, input().split())
abc = [tuple(int(x) for x in input().split()) for _ in range(n)]

c = n * 100 + 1

m = 401

dp = [[[99999 for _ in range(m)] for _ in range(m)] for _ in range(n + 1)]

ans = 99999
dp[0][0][0] = 0
for i in range(n):
    for j in range(m):
        for k in range(m):
            if dp[i][j][k] < 9999:
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k])
                dp[i+1][j+abc[i][0]][k+abc[i][1]] = min(dp[i+1][j+abc[i][0]][k+abc[i][1]], dp[i][j][k] + abc[i][2])
                if (j+abc[i][0]) * mb == (k+abc[i][1]) * ma:
                    ans = min(ans, dp[i+1][j+abc[i][0]][k+abc[i][1]])

if ans == 99999:
    print(-1)
else:
    print(ans)