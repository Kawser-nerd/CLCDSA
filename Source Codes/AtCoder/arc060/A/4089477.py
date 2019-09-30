N, A = map(int, input().split())
cards = list(map(lambda x: int(x)-A, input().split()))

X = max(cards)
X = max(X, A)

dp = [[0]*(2*N*X+1) for _ in range(N+1)]

dp[0][N*X] = 1
for i in range(N):
    for j in range(2*N*X+1):
        c = cards[i]
        if j - c < 0 or j-c > 2*N*X:
            dp[i+1][j] = dp[i][j]
        else:
            dp[i+1][j] = dp[i][j]+dp[i][j-c]


print(dp[N][N*X]-1)