s = input()
dp = [[0]*4 for i in range(len(s)+1)]

dp[0][3] = 1
mod = 1000000007

for i in range(1,len(s)+1):
  if s[i-1] == "A":
    dp[i][0] += dp[i-1][0] + dp[i-1][3]
    dp[i][1] += dp[i-1][1]
    dp[i][2] += dp[i-1][2]
    dp[i][3] += dp[i-1][3]
    
  elif s[i-1] == "B":
    dp[i][0] += dp[i-1][0]
    dp[i][1] += dp[i-1][1] + dp[i-1][0]
    dp[i][2] += dp[i-1][2]
    dp[i][3] += dp[i-1][3]
    
  elif s[i-1] == "C":
    dp[i][0] += dp[i-1][0]
    dp[i][1] += dp[i-1][1]
    dp[i][2] += dp[i-1][2] + dp[i-1][1]
    dp[i][3] += dp[i-1][3]
    
  else:
    dp[i][0] += dp[i-1][0]*3 + dp[i-1][3]
    dp[i][1] += dp[i-1][1]*3 + dp[i-1][0]
    dp[i][2] += dp[i-1][2]*3 + dp[i-1][1]
    dp[i][3] += dp[i-1][3]*3
    
  dp[i][0] %= mod
  dp[i][1] %= mod
  dp[i][2] %= mod
  dp[i][3] %= mod

print(dp[len(s)][2])
#print(dp)