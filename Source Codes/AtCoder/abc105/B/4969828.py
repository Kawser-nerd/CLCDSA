n=int(input())
dp=[0]*101
dp[4]=1
dp[7]=1
for i in range(101):
  if dp[i]==1 and i+4<101:
    dp[i+4]=1
  if dp[i]==1 and i+7<101:
    dp[i+7]=1

if dp[n]==0:
  print('No')
else:
  print('Yes')