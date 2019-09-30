#!/usr/bin/env python3

from copy import deepcopy

MOD = 10 ** 9 + 7
IMAX = 200
JMAX = 2

def dp(n):
    dp = [0 for j in range(JMAX + 1)]
    dp[0] = 1
    for i in reversed(range(IMAX + 1)):
        pre = deepcopy(dp)
        dp[2] += pre[1]
        dp[2] += 2 * pre[2]
        d = ((1 << i) & n) >> i
        if d:
            dp[1] += pre[0]
            dp[2] += pre[1]
        else:
            dp[0] += pre[1]
        dp = take_mod(dp)
    return sum(dp) % MOD

def take_mod(dp):
    res = [x % MOD for x in dp]
    return res

def main():
    n = int(input())
    print(dp(n))

main()