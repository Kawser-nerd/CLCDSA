import bisect
N = int(input())
src = [int(input()) for i in range(N)]
src.sort()
if src[0]*8 > src[-1]:
    print(0)
    exit()
MOD = 10**9+7

dp = [[0 for j in range(N+1)] for i in range(4)]
for i in range(N+1):
    dp[0][N-i] = i
for i in range(1,4):
    for j in range(N-1,-1,-1):
        if src[j]*(2**i) > src[-1]: continue
        k = bisect.bisect_left(src, src[j]*2)
        dp[i][j] = dp[i][j+1] + dp[i-1][k]
print(dp[3][0] % MOD)