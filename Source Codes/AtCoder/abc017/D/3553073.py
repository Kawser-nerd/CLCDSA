N,M = map(int,input().split())
Mod = 10**9+7
from collections import defaultdict
F = [0]*N
for i in range(N):
    F[i] = int(input())
l = [0]*N
used = [False]*(M+1)
j = -1
for i in range(N):
    while True:
        if j == N-1:
            break
        j += 1
        if used[F[j]]:
            j -= 1
            break
        used[F[j]] = True
    l[i] = j-i+1
    used[F[i]] = False
l.reverse()
dp = [0]*N
cdp = [0]*(N+1)
dp[0] = 1
cdp[0] = 1
for i in range(1,N):
    if i-1-l[i] < -1:
        dp[i] = cdp[i-1]+1
    else:
        dp[i] = cdp[i-1]-cdp[i-l[i]-1]
    cdp[i] = cdp[i-1]+dp[i]
    dp[i] %= Mod
    cdp[i] %= Mod
print(dp[N-1])