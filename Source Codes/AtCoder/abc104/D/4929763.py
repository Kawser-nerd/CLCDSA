S = input()
MOD = 10 ** 9 + 7

dp = [1,0,0,0]


for s in S:
    if s == 'A':
        dp[1] += dp[0]
    elif s == 'B':
        dp[2] += dp[1]
    elif s == 'C':
        dp[3] += dp[2]
    elif s == '?':
        dp[3] *= 3
        dp[3] += dp[2]
        dp[2] *= 3
        dp[2] += dp[1]
        dp[1] *= 3
        dp[1] += dp[0]
        dp[0] *= 3

    for i in range(4):
        dp[i] %= MOD


print(dp[3])