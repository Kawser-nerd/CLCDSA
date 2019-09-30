N = int(input())
a = list(map(int,input().split()))
dp = [0]*N
for i in range(N):
    if i == 1:
        dp[1] = abs(a[i] - a[i-1])
    elif i > 1:
        dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]), dp[i-2] + abs(a[i] - a[i - 2]) )
print(dp[-1])