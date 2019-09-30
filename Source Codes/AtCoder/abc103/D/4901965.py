#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
import operator
from queue import Queue
INF = float("inf")


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


def solve(N: int, M: int, a: "List[int]", b: "List[int]"):

    ab = [[x, y] for x, y in zip(a, b)]
    ab.sort(key=operator.itemgetter(1))
    # print(ab)

    cut = [0]                   # i???i+1??????
    for a, b in ab:
        if a <= cut[-1]:         # OK
            continue
        cut.append(b-1)
    print(len(cut)-1)


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    M = int(next(tokens))  # type: int
    a = [int()] * (M)  # type: "List[int]"
    b = [int()] * (M)  # type: "List[int]"
    for i in range(M):
        a[i] = int(next(tokens))
        b[i] = int(next(tokens))
    solve(N, M, a, b)


if __name__ == '__main__':
    main()