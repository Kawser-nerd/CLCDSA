H, W, K = map(int, input().split())
MOD = 10 ** 9 + 7

dp = [[0] * W for _ in range(H+1)]

dp[0][0] = 1


for h in range(H):
    for x in range(W):
        for b in range(2**(W-1)):
            if not '11' in bin(b):
                if x >= 1 and (b>>(x-1)) & 1:
                    dp[h+1][x-1] += dp[h][x]
                    dp[h+1][x-1] %= MOD
                elif x <= W-2 and (b>>x) & 1:
                    dp[h+1][x+1] += dp[h][x]
                    dp[h+1][x+1] %= MOD
                else:
                    dp[h+1][x] += dp[h][x]
                    dp[h+1][x] %= MOD

print(dp[H][K-1])