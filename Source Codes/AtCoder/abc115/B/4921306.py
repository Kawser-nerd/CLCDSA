#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(N: int, p: "List[int]"):
    print(sum(p)-max(p)//2)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    p = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, p)


if __name__ == '__main__':
    main()