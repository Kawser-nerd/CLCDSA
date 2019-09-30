N = int(input())
dp = [0]*(100010)
dp[0] = 0
#dp[N] : N????????????
#dp[N] = min{1+dp[N-1],1+dp[N-6],1+dp[N-9],1+dp[N-6^2],...}

for i in range(1,100010):
  dp[i] = float('inf')
  power = 1
  while(power <= i):
    dp[i] = min(dp[i],dp[i-power]+1)
    power = power*6
  power = 1
  while(power <= i):
    dp[i] = min(dp[i],dp[i-power]+1)
    power = power*9
print(dp[N])