#!/usr/bin/env python3
import sys

MOD = 1000000007  # type: int

def solve(H: int, W: int, K: int):
    comb_ = [[] for _ in range(W)]
    comb_[0] = [0, 1] # yes, no
    for i in range(1, W):
        comb_[i] = [comb_[i - 1][1], sum(comb_[i - 1])]
    comb = []
    for c in comb_:
        comb.append(c[0] + c[1])
    #print(comb)
    # dp[h + 1][w][2]
    dp = [[[0] * 2 for i in range(W)] for _ in range(H + 1)]
    dp[0][0][1] = 1
    for h in range(1, H + 1):
        for w in range(W):
            dp[h][w][0] = dp[h - 1][w][1]
        #print(dp)
        for w in range(W):
            dp[h][w][1] += dp[h][w][0] * comb[max(0, w - 1)] * comb[max(0, W - w - 2)]
            if w > 0:
                dp[h][w][1] += dp[h][w - 1][0] * comb[max(0, w - 2)] * comb[max(0, W - w - 2)]
            if w < W - 1:
                dp[h][w][1] += dp[h][w + 1][0] * comb[max(0, w - 1)] * comb[max(0, W - w - 3)]
    #print(dp)
    ret = dp[H][K - 1][1] % MOD
    print(ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    H = int(next(tokens))  # type: int
    W = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    solve(H, W, K)

if __name__ == '__main__':
    main()