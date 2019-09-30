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
    n, p = LI()
    A = LI()

    sum_a = sum(A)
    # dp[i][j]: a_i??????j????????????i????
    dp = [0] * (sum_a + 1)
    dp[0] = 1
    for i in range(n):
        for j in range(sum_a + 1)[::-1]:
            if j - A[i] < 0:
                break
            if dp[j - A[i]]:
                dp[j] += dp[j - A[i]]

    return sum([dp[i] if i % 2 == p else 0 for i in range(sum_a + 1)])


print(main())