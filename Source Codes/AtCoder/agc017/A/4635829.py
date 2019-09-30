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

    even, odd = 0, 0
    for a in A:
        if a % 2:
            odd += 1
        else:
            even += 1

    if odd:
        return 2 ** (n - 1)
    else:
        return 2 ** n if p == 0 else 0


print(main())