N = int(input())
a = list(map(int, input().split()))
INF = 10 ** 9
dp = [INF] * N
dp[0] = 0
for i in range(0, N):
    if i + 1 < N: 
        dp[i+1] = min(dp[i+1], dp[i] + abs(a[i+1] - a[i]))
    if i + 2 < N:
        dp[i+2] = min(dp[i+2], dp[i+1] + abs(a[i+2] - a[i+1]), dp[i] + abs(a[i+2] - a[i]))
print(dp[N-1])