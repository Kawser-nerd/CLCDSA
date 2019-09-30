# coding:utf-8

import sys
from bisect import bisect_left, bisect_right

INF = float('inf')
MOD = 10 ** 9 + 7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x) - 1 for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def II(): return int(sys.stdin.readline())
def SI(): return input()


def main():
    n, a, b, c, d = LI()

    base = [-INF]
    if n % 2:
        base += list(reversed([a - (2 * c + d - c) * i for i in range(1, (n + 1) // 2)])) + [a + (2 * c + d - c) * i for i in range((n + 1) // 2)]
    else:
        base += list(reversed([a - (d + c) // 2 - (2 * c + d - c) * i for i in range(n // 2)])) + [a + (d + c) // 2 + (2 * c + d - c) * i for i in range(n // 2)]
    base += [INF]

    near = bisect_left(base, b)
    # print(base)
    # print(b, near)

    l = base[near - 1]
    r = base[near]
    x = l if b - l <= r - b else r
    # print(l, r, x)
    if n % 2:
        tmp = ((n + 1) // 2 - 1) * (d - c)
        # print(tmp)
        if x - tmp <= b <= x + tmp:
            res = 'YES'
        else:
            res = 'NO'
    else:
        tmp = (n // 2 - 1) * (d - c) + (d - c) // 2
        # print(tmp)
        if (d - c) % 2:
            if a <= b:
                if x - tmp <= b <= x + tmp + 1:
                    res = 'YES'
                else:
                    res = 'NO'
            else:
                if x - tmp - 1 <= b <= x + tmp:
                    res = 'YES'
                else:
                    res = 'NO'
        else:
            if x - tmp <= b <= x + tmp:
                res = 'YES'
            else:
                res = 'NO'

    return res


print(main())