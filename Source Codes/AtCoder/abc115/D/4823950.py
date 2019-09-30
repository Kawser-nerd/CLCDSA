#!/usr/bin/env python3
import sys


def solve(N: int, X: int):
    total = [0] * (N + 1)
    p = [0] * (N + 1)
    total[0] = 1
    p[0] = 1
    for i in range(1, N + 1):
        total[i] = total[i - 1] * 2 + 3
        p[i] = p[i - 1] * 2 + 1
    def rec(idx, x):
        if x <= 0:
            return 0
        if x >= total[idx] - idx:
            return p[idx]
        elif x <= total[idx] // 2:
            return rec(idx - 1, x - 1)
        else:
            rest = x - (total[idx] // 2 + 1)
            ret = p[idx - 1] + 1 + rec(idx - 1, rest)
        return ret
    ret = rec(N, X)
    print(ret)
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