#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
INF = float("inf")

MOD = 1000000007  # type: int

d = {}


def thpow(q):
    if q < 0:
        return 0
    if q == 0:
        return 1
    if q in d:
        return d[q]
    else:
        d[q] = (3*thpow(q-1)) % MOD
        return d[q]


def solve(S: str):
    dp = [0, 0, 0]
    q = 0
    for ch in S:
        a, b, c = dp
        if ch == "A":
            dp = [(a+thpow(q)) % MOD, b, c]
        elif ch == "B":
            dp = [a, (b+a) % MOD, c]
        elif ch == "C":
            dp = [a, b, (c+b) % MOD]
        elif ch == "?":
            dp = [((a*3 % MOD)+thpow(q)) % MOD,
                  ((b*3) % MOD+a) % MOD,
                  ((c*3)+b) % MOD]
            q += 1
        # print(dp)
    # print(dp)

    # print(d)
    print(dp[2])
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    S = next(tokens)  # type: str
    solve(S)


if __name__ == '__main__':
    main()