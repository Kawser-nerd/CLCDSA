#!/usr/bin/env python3

from heapq import *


def solve(N, K):
    blocks = []
    counts = dict()

    heappush(blocks, -N)  # XXX: can't we just use a max-heap?
    counts[N] = 1

    L, R = None, None
    ub = 0

    while blocks:
        block = -heappop(blocks)
        count = counts[block]
        ub += count

        L = (block - 1) // 2
        R = block // 2

        if K <= ub:
            return '%d %d' % (R, L)

        if L > 0:
            if L in counts:
                counts[L] += count
            else:
                heappush(blocks, -L)
                counts[L] = count

        if R > 0:
            if R in counts:
                counts[R] += count
            else:
                heappush(blocks, -R)
                counts[R] = count


T = int(input())

for case_number in range(1, T+1):
    N, K = map(int, input().split())
    print('Case #%d:' % case_number, solve(N, K))
