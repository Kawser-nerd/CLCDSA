H, W, K = map(int, input().split())
mod = 10 ** 9 + 7
dp = [[0] * W for i in range(H + 1)]

dp[0][0] = 1
for i in range(H):
    for j in range(W):
        for k in range(1 << (W - 1)):
            flag = True
            if '11' in bin(k):
                flag = False
            if flag:
                if j >= 1 and (k >> (j - 1)) & 1:
                    dp[i + 1][j - 1] += dp[i][j]
                    dp[i + 1][j - 1] %= mod
                elif j <= W - 1 and (k >> j) & 1:
                    dp[i + 1][j + 1] += dp[i][j]
                    dp[i + 1][j + 1] %= mod
                else:
                    dp[i + 1][j] += dp[i][j]
                    dp[i + 1][j] %= mod
                    
print(dp[-1][K - 1])