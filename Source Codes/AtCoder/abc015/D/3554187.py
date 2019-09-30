W = int(input())
N,K = map(int,input().split())
A = []
B = []
for i in range(N):
    a,b = map(int,input().split())
    A.append(a)
    B.append(b)
import numpy as np
dp = np.zeros((N+1,N+1,W+1))
for i in range(N):
    for j in range(1,N+1):
        dp[i+1][j] = dp[i][j]
        if 0 <= W-A[i]:
            dp[i+1][j][A[i]:] = np.maximum(dp[i][j][A[i]:],dp[i][j-1][:W-A[i]+1]+B[i])

ans = 0
for i in range(1,K+1):
    ans = int(max(ans,dp[N][i][W]))
print(ans)