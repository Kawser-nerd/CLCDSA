#!/usr/bin/env python3
import sys
import functools
INF = float("inf")

MOD = 1000000007  # type: int


@functools.lru_cache(maxsize=None)
def f(x):
    if x <= 0:
        return 1
    elif x == 1:
        return 2
    else:
        return f(x-1) + f(x-2)


def solve(H: int, W: int, K: int):

    dp = [0]*(W+2)
    dp[1] = 1                   # ??????
    for h in range(H):
        buf = [0]*(W+2)
        for i in range(1, W+1):
            # ??????
            buf[i] += dp[i-1]*f(i-3)*f(W-i-1)
            buf[i] %= MOD
            # ???????
            buf[i] += dp[i]*f(i-2)*f(W-i-1)
            buf[i] %= MOD
            # ??????
            buf[i] += dp[i+1]*f(i-2)*f(W-i-2)
            buf[i] %= MOD
        for i in range(1, W+1):
            dp[i] = buf[i]
    print(dp[K])

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