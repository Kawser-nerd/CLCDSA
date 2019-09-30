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
    n = II()
    A = [II() for _ in range(n)]

    res = 0
    mod = 0
    for a in A:
        if not a:
            mod = 0
            continue
        q, mod = divmod(a + mod, 2)
        res += q

    return res


print(main())