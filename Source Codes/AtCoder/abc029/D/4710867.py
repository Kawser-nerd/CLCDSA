s = input()
n = len(s)
dp = [[[0 for k in range(20)] for j in range(2)] for i in range(n+1)]
dp[0][0][0] = 1
for i in range(n):
    for j in range(2):
        for k in range(11):
            x = 9 if j else int(s[i])
            for d in range(x+1):
                dp[i+1][j or (d<x)][k + (d==1)] += dp[i][j][k]
ans = 0
for j in range(2):
    for k in range(11):
        ans += dp[n][j][k] * k
print(ans)