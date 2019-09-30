#!/usr/bin/env python3
import sys


def solve(N: int, M: int):
    ret = 0
    i = 1
    while i * i <= M:
        if M % i == 0:
            if i >= N:
                ret = max(ret, M // i)
            if M // i >= N:
                ret = max(ret, i)
        i += 1
    print(ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    solve(N, M)

if __name__ == '__main__':
    main()