n,m = map(int,input().split())
f = [int(input()) for i in range(n)]
MOD = 10**9+7

dp = [0]*(n+1)
dp[0] = 1
dp[1] = 1

ruiseki = [0]*(n+1)
ruiseki[0] = 1
ruiseki[1] = 2
memo = {}
memo[f[0]] = 0
pos = -1
for i in range(1,n):
  
  if f[i] not in memo:
    if pos == -1:
      dp[i+1] = ruiseki[i]
      ruiseki[i+1] = ruiseki[i] + dp[i+1]
      memo[f[i]] = i
    else:
      dp[i+1] = ruiseki[i]-ruiseki[pos]
      ruiseki[i+1] = ruiseki[i] + dp[i+1]
      memo[f[i]] = i
  else:
    if memo[f[i]] > pos:
      dp[i+1] = ruiseki[i] - ruiseki[memo[f[i]]]
      ruiseki[i+1] = ruiseki[i] + dp[i+1]
      pos = memo[f[i]]
      memo[f[i]] = i
    else:
      dp[i+1] = ruiseki[i] - ruiseki[pos]
      ruiseki[i+1] = ruiseki[i] + dp[i+1]
      memo[f[i]] = i
  dp[i+1] %= MOD 
  ruiseki[i+1] %= MOD 
print(dp[n]%MOD)