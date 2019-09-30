MOD = 10**9+7
N = int(input())
C = [int(input()) for i in range(N)]

dp = [0 for i in range(N)]
dp[0] = 1

color = {}
for c in C:
    color[c] = 0
color[C[0]] = 1

for i in range(1,N):
    dp[i] = dp[i-1]
    if C[i-1] != C[i]:
        dp[i] = (dp[i] + color[C[i]])%MOD
    color[C[i]] = dp[i]
print(dp[-1])