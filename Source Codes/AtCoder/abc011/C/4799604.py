n=int(input())
n1=int(input())
n2=int(input())
n3=int(input())
dp=[10**18 for i in range(301)]
dp[0]=0
for i in range(1,301):
  if i==1:
    dp[i]=dp[0]+1
  elif i==2:
    dp[i]=min(dp[i-1]+1,dp[i-2]+1)
  dp[i]=min(dp[i-1]+1,dp[i-2]+1,dp[i-3]+1)
  if i==n1 or i==n2 or i==n3:
    dp[i]=10**18
if dp[n]>100:
  print("NO")
else:
  print("YES")