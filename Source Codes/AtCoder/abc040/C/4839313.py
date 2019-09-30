N = int(input())
a = [int(i) for i in input().split()]
dp = [0]*N

dp[0] = 0
dp[1] = abs(a[1]-a[0])

for i in range(2,N):
  dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]),dp[i-2] + abs(a[i]-a[i-2]))

print(dp[-1])