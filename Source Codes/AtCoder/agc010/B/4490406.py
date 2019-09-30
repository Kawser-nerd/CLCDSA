# coding:utf-8

import sys
# from collections import Counter, defaultdict

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    n = II()
    A = LI()

    # 1. A??????????????
    k, mod = divmod(sum(A), (n * (n + 1) // 2))
    if mod:
        return 'NO'

    A.append(A[0])
    diff = []
    for a1, a2 in zip(A[:-1], A[1:]):
        diff.append(a2 - a1)

    # 2. ????????????
    # ??????1??dk?-(n - 1), ?????+1???

    # 3. {di - k}????n??????????????
    return 'YES' if not any([(d - k) % n or d > k for d in diff]) else 'NO'


print(main())