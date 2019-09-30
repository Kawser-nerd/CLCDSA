H, W, K = map(int, input().split())
MOD = 10 ** 9 + 7


def transition(w):
    X = [1, 2, 3, 5, 8, 13, 21, 34]
    if w >= 0:
        return X[w]
    else:
        return 1


# h?w????????
dp = [[0] * W for h in range(H + 1)]
dp[0][0] = 1

for h in range(H):
    for w in range(W):
        # ???
        dp[h + 1][w] += dp[h][w] * (transition(w - 1) * transition(W - w - 2))
        dp[h + 1][w] %= MOD

        # ???
        if w + 1 < W:
            dp[h + 1][w + 1] += dp[h][w] * (transition(w - 1) * transition(W - w - 3))
            dp[h + 1][w + 1] %= MOD

        # ???
        if w - 1 >= 0:
            dp[h + 1][w - 1] += dp[h][w] * (transition(w - 2) * transition(W - w - 2))
            dp[h + 1][w - 1] %= MOD

print(dp[H][K - 1])