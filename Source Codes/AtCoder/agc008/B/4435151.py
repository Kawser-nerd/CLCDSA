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
    n, k = LI()
    A = LI()

    C = [0]
    C2 = [0]
    for a in A:
        C.append(C[-1] + a)
        if a < 0: a = 0
        C2.append((C2[-1] + a))

    ans = 0
    # ???[j, j+k)???????????????????????
    # ai > 0?????????????
    for i in range(n - k + 1):
        ans = max(ans, max(C[i + k] - C[i], 0) + C2[i] + C2[-1] - C2[i + k])

    return ans


print(main())