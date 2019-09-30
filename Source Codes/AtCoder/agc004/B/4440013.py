# coding:utf-8

import sys

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    n, x = LI()
    A = LI()

    min_a, min_i = INF, -1
    res = 0
    for i, a in enumerate(A):
        if a < min_a:
            min_a = a
            min_i = i
        res += a
    A = A[min_i:] + A[:min_i]

    dp = [INF] + A
    for k in range(n - 1):
        tmp = 0
        for i in range(n)[::-1]:
            if dp[i + 1] > dp[i]:
                dp[i + 1] = dp[i]
            tmp += dp[i + 1]

        res = min(res, tmp + (k + 1) * x)

    return res


print(main())