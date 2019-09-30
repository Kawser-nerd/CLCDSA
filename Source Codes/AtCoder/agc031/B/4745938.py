N = int(input())
C = [int(input()) for i in range(N)]
MOD = 10**9+7

dp = [0] * N
dp[0] = 1
bak = {C[0]:0}

for i,c in enumerate(C):
    if i==0: continue
    dp[i] = dp[i-1]
    if c in bak and bak[c] < i-1:
        dp[i] += dp[bak[c]]
        dp[i] %= MOD
    bak[c] = i
print(dp[-1])