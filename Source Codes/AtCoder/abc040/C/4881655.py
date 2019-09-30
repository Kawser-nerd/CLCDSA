n = int(input())
a = list(map(int, input().split()))

dp = [0]*n
for i in range(n):
  if i == 0:
    dp[i] = 0
  elif i == 1:
    dp[i] = dp[i-1]+abs(a[i]-a[i-1])
  else:
    dp[i] = min(dp[i-2]+abs(a[i]-a[i-2]), dp[i-1]+abs(a[i]-a[i-1]))
print(dp[-1])