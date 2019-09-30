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
    n, l = LI()
    A = LI()

    for i in range(n - 1):
        if A[i] + A[i + 1] >= l:
            k = i
            print('Possible')
            break
    else:
        print('Impossible')
        return 0

    for i in range(k):
        print(i + 1)

    for i in range(k, n - 1)[::-1]:
        print(i + 1)

    return 1


main()