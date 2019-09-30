#!/usr/bin/env python3

import sys


def rl(T):
    return list(map(T, input().split()))


def up_solve(A):
    iv = 0
    n = len(A)
    for i in range(n):
        for j in range(i + 1, n):
            if A[i] > A[j]:
                iv += 1
    #print('up_solve', A, iv)
    return iv


def down_solve(A):
    return up_solve(A[::-1])


def count_larger(l, v):
    return len([_ for _ in l if _ > v])


def solve(A):
    return sum(min(count_larger(A[:i], A[i]), count_larger(A[i:], A[i])) for i in range(len(A)))


def main():
    sys.setrecursionlimit(100000)
    T, = rl(int)
    for C in range(1, T + 1):
        N, = rl(int)
        A = rl(int)

        ans = solve(A)

        print('Case #%d: %d' % (C, ans))
    pass


main()