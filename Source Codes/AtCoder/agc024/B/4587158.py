N=int(input())
dp=[0]*(N+1)
for _ in range(N):
  x=int(input())
  dp[x]=dp[x-1]+1
print(N-max(dp))