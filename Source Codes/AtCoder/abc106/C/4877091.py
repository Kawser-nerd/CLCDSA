#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
# import numpy as np
INF = float("inf")


def solve(S: int, K: int):
    n = -1
    nc = 1
    for i, c in enumerate(str(S)):
        if c != "1":
            n = i+1
            nc = c
            break
    # print(n, nc, K)
    if n == -1:
        print(1)
        return

    if K < n:
        print(1)
    else:
        print(nc)

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    S = int(next(tokens))  # type: int
    K = int(next(tokens))  # type: int
    solve(S, K)


if __name__ == '__main__':
    main()