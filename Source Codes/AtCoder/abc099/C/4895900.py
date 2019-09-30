N = int(input())
dp = [N]*(N+1)
dp[0] = 0

for i in range(N+1):
  for j in [6**i for i in range(7)]:
    if i+j <= N:
      dp[i+j] = min(dp[i+j],dp[i]+1)
  for j in [9**i for i in range(1,6)]:
    if i+j <= N:
      dp[i+j] = min(dp[i+j],dp[i]+1)

print(dp[-1])