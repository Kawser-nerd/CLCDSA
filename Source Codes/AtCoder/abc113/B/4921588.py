#!/usr/bin/env python3
import sys
INF = float("inf")


def argmin(a):
    m, n = INF, -1
    for i, v in enumerate(a):
        if m > v:
            m, n = v, i
    return m, n


def solve(N: int, T: int, A: int, H: "List[int]"):
    print(argmin([abs(T-h*0.006-A) for h in H])[1]+1)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    T = int(next(tokens))  # type: int
    A = int(next(tokens))  # type: int
    H = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, T, A, H)


if __name__ == '__main__':
    main()