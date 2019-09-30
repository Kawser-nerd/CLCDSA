#!/usr/bin/env python3
import sys
import itertools
import collections
import functools
import math
from queue import Queue
INF = float("inf")


def solve(N: int):
    ans = []
    kari = 0
    p = 1                       # ??
    for i in range(40):
        c = N & 1               # ???bit
        if c == ((kari >> i) & 1):
            ans.append(0)
        else:
            ans.append(1)
            kari += p
        N >>= 1
        p *= -2

    if 1 in ans:
        i = ans[::-1].index(1)
        print(*ans[::-1][i:], sep="")
    else:
        print(0)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    solve(N)


if __name__ == '__main__':
    main()