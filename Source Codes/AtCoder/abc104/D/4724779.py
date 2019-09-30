S = input()

dp = [ [ 0 for _ in range(4)] for _ in range(len(S)+10) ]
dp[0][0] = 1

mod = 10**9+7

for i in range(len(S)):
    for j in range(4):
        if S[i] != '?':
            dp[i+1][j] += dp[i][j]
            dp[i+1][j] %= mod
        else:
            dp[i+1][j] += dp[i][j]*3
            dp[i+1][j] %= mod

    if S[i] == 'A' or S[i] == '?':
        dp[i+1][1] += dp[i][0]
        dp[i+1][1] %= mod

    if S[i] == 'B' or S[i] == '?':
        dp[i+1][2] += dp[i][1]
        dp[i+1][2] %= mod

    if S[i] == 'C' or S[i] == '?':
        dp[i+1][3] += dp[i][2]
        dp[i+1][3] %= mod

print (dp[len(S)][3])