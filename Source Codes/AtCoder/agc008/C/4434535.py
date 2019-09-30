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
    # ai, ao, at, aj, al, as, az
    A = LI()

    res = 0
    for e in (0, 3, 4):
        res += A[e] // 2 * 2

    if all([A[0], A[3], A[4]]):
        tmp = 3
        for e in (0, 3, 4):
            tmp += (A[e] - 1) // 2 * 2
        if res < tmp:
            res = tmp

    return res + A[1]


print(main())