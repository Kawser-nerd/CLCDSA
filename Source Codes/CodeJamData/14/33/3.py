#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N, M, K = map(int, fin.readline().split())
    N, M = min([N, M]), max([N, M])
    result = K
    if N == 1:
        result = K
    else:
        for l in range(0, M-1):
            for h1 in range(0, N-1):
                for h2 in range(0, h1+1):
                    stones = l*2 + h1 + h2
                    diff = h1 - h2
                    if diff >= l:
                        continue
                    rect = l * h1
                    triangle = diff*(diff+1)//2

                    covered = rect - triangle + stones
                    if covered > K:
                        continue
                    required = stones + K - covered
                    result = min(result, required)


    print("Case #%d: %s" % (case, result))