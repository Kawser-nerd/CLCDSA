#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(X: int, Y: int):
    print(X+Y//2)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    X = int(next(tokens))  # type: int
    Y = int(next(tokens))  # type: int
    solve(X, Y)


if __name__ == '__main__':
    main()