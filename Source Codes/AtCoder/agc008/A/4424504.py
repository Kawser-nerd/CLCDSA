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
    x, y = LI()

    if abs(x) <= abs(y):
        cnt = abs(y) - abs(x)
        if x >= 0:
            if y < 0:
                cnt += 1
        else:
            if y >= 0:
                cnt += 1
            else:
                cnt += 2
    else:
        cnt = abs(x) - abs(y)
        if x <= 0:
            if y > 0:
                cnt += 1
        else:
            if y <= 0:
                cnt += 1
            else:
                cnt += 2

    return cnt


print(main())