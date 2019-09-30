import sys
sys.setrecursionlimit(1000000)

N = int(input())
dp = [0]*(N+1)

def fun(n):
  if n == 0:
    return 0
  elif dp[n] != 0:
    return dp[n]
  
  ans = N
  for i in [6**k for k in range(7)]:
    if i <= n:
      ans = min(ans, fun(n-i) + 1)
  for j in [9**l for l in range(6)]:
    if j <= n:
      ans = min(ans, fun(n-j) + 1)
  
  dp[n] = ans
  return dp[n]

fun(N)
print(dp[-1])