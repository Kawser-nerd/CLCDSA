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
    s = SI()

    res = 0
    for i in range(len(s)):
        u = len(s) - i - 1
        d = len(s) - u - 1
        if s[i] == 'U':
            res += u + 2 * d
        else:
            res += 2 * u + d

    return res


print(main())