import bisect
N = int(input())
L = []
for i in range(N):
  L.append(int(input()))
dp = [float('inf')]*N
for i in range(N):
  k = bisect.bisect_left(dp,L[i])
  dp[k] = L[i]
endnum = bisect.bisect_left(dp,N+1)
print(N-endnum)