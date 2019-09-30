# coding:utf-8

import sys

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    n = II()
    P = [II() for _ in range(n)]

    # dp[i]: ???i????????????????????
    dp = [0] * (n + 1)
    for p in P:
        dp[p] += dp[p - 1] + 1

    return n - max(dp)


print(main())