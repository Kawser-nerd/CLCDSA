#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(D: int, N: int):
    if N != 100:
        print(str(N)+"00"*D)
    else:
        N = "101"
        print(str(N) + "00"*D)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    D = int(next(tokens))  # type: int
    N = int(next(tokens))  # type: int
    solve(D, N)


if __name__ == '__main__':
    main()