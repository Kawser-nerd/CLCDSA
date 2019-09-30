import sys
sys.setrecursionlimit(1000000)

N = int(input())
a = [int(i) for i in input().split()]
dp = [0]*N

dp[0] = 0
dp[1] = abs(a[1]-a[0])

def dpdfs(n):
  if n==0:
    return dp[0]
  elif n==1:
    return dp[1]
  
  if dp[n] != 0:
    return dp[n]
  
  dp[n] = min(dpdfs(n-1) + abs(a[n]-a[n-1]),dpdfs(n-2) + abs(a[n]-a[n-2]))
  return dp[n]

dpdfs(N-1)
#for i in range(2,N):
#  dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]),dp[i-2] + abs(a[i]-a[i-2]))

print(dp[-1])