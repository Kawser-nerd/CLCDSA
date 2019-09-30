n, w = map(int, input().split())

dp = [[[-1]*4*n for j in range(n+1)] for i in range(n+1)]
dp[0][0][0] = 0
w1 = None
for i in range(n):
    ws, vs = map(int, input().split())
    if i == 0:
        w1 = ws
    ws -= w1
    for j in range(i+2):
        for k in range(4*n):
            if j-1 >= 0 and k-ws >= 0 and dp[i][j-1][k-ws] >= 0:
                dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-1][k-ws]+vs)
            else:
                dp[i+1][j][k] = dp[i][j][k]

ans = 0
for j in range(n+1):
    for k in range(4*n):
        if w1*j + k <= w:
            ans = max(ans, dp[-1][j][k])
print(ans)