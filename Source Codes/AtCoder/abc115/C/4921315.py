#!/usr/bin/env python3
import sys
INF = float("inf")


def solve(N: int, K: int, h: "List[int]"):
    h.sort()
    print(min(h[i+K-1]-h[i] for i in range(N-K+1)))

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    h = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, K, h)


if __name__ == '__main__':
    main()