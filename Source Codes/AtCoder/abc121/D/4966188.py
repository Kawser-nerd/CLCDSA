#!/usr/bin/env python3
import sys
INF = float("inf")


def f(n):
    if n % 2 == 0:
        if (n//2) % 2 == 0:
            return n
        else:
            return 1 ^ n
    else:
        if ((n+1)//2) % 2 == 0:
            return 0
        else:
            return 1


def solve(A: int, B: int):
    # print(f(B))
    # print(f(A-1))
    print(f(B) ^ f(A-1))

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    A = int(next(tokens))  # type: int
    B = int(next(tokens))  # type: int
    solve(A, B)


if __name__ == '__main__':
    main()