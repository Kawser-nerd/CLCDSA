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
    P = LI()

    # ???a_i?a_i+1???n?????
    A = [n * i + 1 for i in range(1, n + 1)]
    B = A[::-1]

    # ?????????i?A[i] + B[i]????
    # A[i]?B[i]???P????????????A[i]??????
    # A[i]?????????n????
    # ???A[i]?1??????????A??????????
    for i, p in enumerate(P):
        A[p - 1] -= n - i

    print(*A)
    print(*B)
    # print([A[i] + B[i] for i in range(n)])


main()