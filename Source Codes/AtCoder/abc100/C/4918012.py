#!/usr/bin/env python3
import sys
INF = float("inf")

import math
import collections


def solve(N: int, a: "List[int]"):
    print(int(sum([math.log2(v & -v) for v in a])))
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    a = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, a)


if __name__ == '__main__':
    main()