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
    n, x = LI()

    if x == 1 or x == 2 * n - 1:
        print('No')
        return 0

    print('Yes')
    if n < 3:
        print(*[n for n in range(1, 2 * n)], sep='\n')
        return 1

    # n - 1?????2??x?????????
    if x == 2:
        tmp = [3, 2, 1, 4]
    else:
        tmp = [x - 1, x, x + 1, x - 2]

    remain = list(set([n for n in range(1, 2 * n)]) - set(tmp))
    k = 3 - n
    tmp = remain[:k] + tmp + remain[k:]
    print(*tmp, sep='\n')

    return 1


main()