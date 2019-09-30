#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
# import numpy as np
INF = float("inf")


def solve(N: int, M: int, Q: int, L: "List[int]", R: "List[int]", p: "List[int]", q: "List[int]"):
    a = [[0]*(N+1) for _ in range(N+1)]
    for l, r in zip(L, R):
        a[l][r] += 1

    a = [list(itertools.accumulate(x)) for x in a]
    a = [list(itertools.accumulate(s[::-1]))[::-1] for s in zip(*a)]

    for pp, qq in zip(p, q):
        # ????????
        print(a[qq][pp])
    # print(*a, sep="\n")

    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    Q = int(next(tokens))  # type: int
    L = [int()] * (M)  # type: "List[int]"
    R = [int()] * (M)  # type: "List[int]"
    for i in range(M):
        L[i] = int(next(tokens))
        R[i] = int(next(tokens))
    p = [int()] * (Q)  # type: "List[int]"
    q = [int()] * (Q)  # type: "List[int]"
    for i in range(Q):
        p[i] = int(next(tokens))
        q[i] = int(next(tokens))
    solve(N, M, Q, L, R, p, q)


if __name__ == '__main__':
    main()