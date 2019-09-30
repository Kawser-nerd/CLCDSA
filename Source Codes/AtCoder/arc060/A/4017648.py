N, A = map(int, input().split())

x = list(map(int, input().split()))


X = max(max(x), A)

dp = [[0 for i in range(2*N*X+1)] for j in range(N+1)]

dp[0][N*X] = 1

y = []

for i in range(N):
    tmp = x[i]-A
    y.append(tmp)

for i in range(N):
    for j in range(2*N*X+1):
        if j-y[i]<0 or j-y[i]>2*N*X:
            dp[i+1][j] = dp[i][j]
        else:
            dp[i+1][j] = dp[i][j] + dp[i][j-y[i]]
            
print(dp[N][N*X]-1)