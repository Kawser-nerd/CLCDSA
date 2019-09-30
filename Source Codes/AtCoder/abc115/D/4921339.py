#!/usr/bin/env python3
import sys
import functools
INF = float("inf")


@functools.lru_cache(None)
def hight(n):
    if n == 0:
        return 1
    else:
        return 2*hight(n-1)+3


@functools.lru_cache(None)
def paty(n):
    if n == 0:
        return 1
    else:
        return 2*paty(n-1)+1


def rec(n, x):
    # print(n, x)
    if n == 0:
        if x == 0:
            return 0
        else:
            return 1

    if x == 0:
        return 0
    elif x == 1:
        return 0
    elif x < hight(n-1)+2:
        return rec(n-1, x-1)
    elif x == hight(n-1)+2:
        return paty(n-1) + 1
    else:
        # print(paty(n-1)+1)
        return paty(n-1)+1 + rec(n-1, x-(hight(n-1)+2))


def solve(N: int, X: int):
    print(rec(N, X))

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    X = int(next(tokens))  # type: int
    solve(N, X)


if __name__ == '__main__':
    main()