N,K = map(int,input().split())

dp = [[[0,0] for j in range(K+2)] for i in range(N+1)]
for j in range(K+1):
    dp[N][j][1] = 1.0

for i in reversed(range(N)):
    for j in range(K+1):
        if j > i: break
        for k in range(2):
            dp[i][j][k] = i/(i+1) * dp[i+1][j][k] +\
             max(dp[i+1][j+1][1], dp[i+1][j][0]) / (i+1)

print(dp[0][0][0])