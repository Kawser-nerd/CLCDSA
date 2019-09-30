MOD = 10 ** 9 + 7

N = int(input())

binN = list(map(int, bin(N)[2:]))
dp = [[0] * 3 for _ in range(len(binN) + 1)]
dp[0][0] = 1
for i, Ni in enumerate(binN):
    dp[i + 1][0] += dp[i][0] * 1
    dp[i + 1][1] += dp[i][0] * Ni
    dp[i + 1][0] += dp[i][1] * (1 - Ni)
    dp[i + 1][1] += dp[i][1] * 1
    dp[i + 1][2] += dp[i][1] * (1 + Ni)
    dp[i + 1][2] += dp[i][2] * 3
    dp[i + 1][0] %= MOD
    dp[i + 1][1] %= MOD
    dp[i + 1][2] %= MOD

print(sum(dp[-1]) % MOD)