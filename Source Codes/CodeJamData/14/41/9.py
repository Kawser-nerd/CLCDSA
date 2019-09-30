#!/usr/bin/env python3

import sys

def rl(T):
    return list(map(T, input().split()))


def solve(X, S):
    if len(S) == 0:
        return 0
    if len(S) == 1:
        return 1
    if S[0] + S[-1] <= X:
        return 1 + solve(X, S[1:len(S) - 1])
    if S[-1] <= X:
        return 1 + solve(X, S[0:len(S) - 1])
    raise Exception


def main():
    sys.setrecursionlimit(100000)
    T, = rl(int)
    for C in range(1, T + 1):
        N, X = rl(int)
        S = rl(int)

        S.sort()

        ans = solve(X, S)

        print('Case #%d: %d' % (C, ans))
    pass


main()