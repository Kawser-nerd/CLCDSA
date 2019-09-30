#!/usr/bin/env python3
import sys
INF = float("inf")


def yes():
    print("Yes")  # type: str


def no():
    print("No")  # type: str


def solve(N: str):
    S = 0
    for c in N:
        S += int(c)
    N = int(N)

    if N % S == 0:
        yes()
    else:
        no()

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = str(next(tokens))  # type: str
    solve(N)


if __name__ == '__main__':
    main()