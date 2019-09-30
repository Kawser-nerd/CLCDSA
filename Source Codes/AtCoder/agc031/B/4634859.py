import sys
readline = sys.stdin.readline

N = int(readline())
MOD = 10**9 + 7
last = [-1]*(3*10**5)
dp = [0]*(N+1)
dp[0] = 1
for i in range(1, N+1):
    c = int(readline())
    if last[c] != -1 and last[c]+1 < i:
        dp[i] = (dp[last[c]] + dp[i-1]) % MOD
    else:
        dp[i] = dp[i-1]
    last[c] = i
print(dp[N])