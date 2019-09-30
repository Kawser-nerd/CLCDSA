#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
# import numpy as np
INF = float("inf")


class Bit:
    def __init__(self, n, m):
        self.size = [n, m]
        self.tree = [[0] * (n + 1) for _ in range(m+1)]

    def sum(self, i, j):
        s = 0
        while i > 0:
            jj = j
            while jj > 0:
                s += self.tree[i][jj]
                jj -= jj & -jj
            i -= i & -i
        return s

    def add(self, i, j, x):
        while i <= self.size[0]:
            jj = j
            while jj <= self.size[1]:
                self.tree[i][jj] += x
                jj += jj & -jj
            i += i & -i


def solve(N: int, M: int, Q: int, L: "List[int]", R: "List[int]", p: "List[int]", q: "List[int]"):
    b = Bit(N, N)

    for l, r in zip(L, R):
        b.add(N-l+1, r, 1)

    for pp, qq in zip(p, q):
        print(b.sum(N-pp+1, qq))

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