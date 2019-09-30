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

    b, a = sorted([x, n - x])
    ans = a + b
    while b:
        q, mod = divmod(a, b)
        ans += (2 * q - (not mod)) * b
        a, b = b, mod

    return ans


print(main())