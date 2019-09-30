N = int(input())
dp = [float('inf')]*100001
dp[0],dp[1] = 0,1
L = [1,6,36,216,1296,7776,46656,9,81,729,6561,59049]
for i in range(2,100001):
  for j in range(len(L)):
    if i-L[j] >= 0:
      dp[i] = min(dp[i-L[j]]+1,dp[i])
print(dp[N])