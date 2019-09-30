N = int(input())
dp = [N] *(N+10)
dp[0] = 0

for i in range(1,N+1):
    for p in range(N+1):
        p = 6**p
        if p > N:
            break
        dp[i] = min(dp[i],dp[i-p]+1)
    for p in range(N+1):
        p = 9**p
        if p > N:
            break
        dp[i] = min(dp[i],dp[i-p]+1)

print(dp[N])