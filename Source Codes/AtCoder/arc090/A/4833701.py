n = int(input())
a = [None]*2
a[0] = list(map(int,input().split()))
a[1] = list(map(int,input().split()))

dp = [[0]*n for i in range(2)]
dp[0][0] = a[0][0]

for i in range(n):
    if i == 0:
        dp[1][i] = dp[0][i]+a[1][i]
    else:
        dp[0][i] = dp[0][i-1]+a[0][i]
        dp[1][i] = max(dp[0][i],dp[1][i-1])+a[1][i]

print(dp[1][n-1])