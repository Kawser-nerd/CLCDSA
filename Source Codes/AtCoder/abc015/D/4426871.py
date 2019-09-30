W = int(input())
N, K = map(int, input().split())
A, B = [], []
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

inf = float("inf")
dp = [[inf for i in range(100*N+1)] for i in range(N+1)]
dp[0][0] = 0

total = 0
for i in range(N):
    a, b = A[i], B[i]
    for j in range(i, -1, -1):
        for v in range(total, -1, -1):
            dp[j+1][v+b] = min(dp[j+1][v+b], dp[j][v]+a)
    total += b

res = 0
for i in range(1,K+1):
    for j in range(100*N+1):
        if dp[i][j] <= W:
            res = max(res, j)
print(res)