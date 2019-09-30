#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
INF = float("inf")
from operator import mul
from functools import reduce


def cmb(n, r):
    r = min(n-r, r)
    if r == 0:
        return 1
    numer = reduce(mul, range(n, n - r, -1))
    denom = reduce(mul, range(1, r + 1))
    return numer // denom


def solve(N: int, M: int, A: "List[int]"):
    B = itertools.accumulate(A)
    c = collections.Counter()
    for b in B:
        c[b % M] += 1
    print(c[0]+sum([cmb(c[k], 2)for k in c if c[k] > 1]))
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    A = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, M, A)


if __name__ == '__main__':
    main()