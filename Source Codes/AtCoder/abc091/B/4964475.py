# coding:utf-8

import sys
from collections import Counter, defaultdict

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    n = II()
    blue = defaultdict(int)
    for _ in range(n):
        blue[SI()] += 1
        
    m = II()
    red = defaultdict(int)
    for _ in range(m):
        red[SI()] += 1

    res = 0
    for key, v in blue.items():
        res = max(res, v - red[key])

    return res


print(main())