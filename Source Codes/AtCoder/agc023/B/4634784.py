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
    B = [tuple(SI()) for _ in range(n)]

    BT = list(zip(*B))
    res = 0
    for a in range(n):
        is_good = True
        for i in range(n):
            if B[i][n - a:] + B[i][:n - a] != BT[(i - a) % n]:
                is_good = False

        if is_good:
            res += n

    return res


print(main())