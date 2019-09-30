#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys

def debug(*args):
    print(*args, file=sys.stderr)

def permutations(n, k):
    if k == 0:
        yield [False]*n
        return
    for p in permutations(n-1, k-1):
        yield p + [True]
    if n > k:
        for p in permutations(n-1, k):
            yield p + [False]

def cost(p, r, c):
    result = 0
    for i in range(r):
        for j in range(c-1):
            if p[i*c+j] and p[i*c+j+1]:
                result += 1
    for i in range(r-1):
        for j in range(c):
            if p[i*c+j] and p[i*c+j+c]:
                result += 1
    return result



fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    R, C, N = map(int, fin.readline().split())

    best = R*C*10
    for p in permutations(R*C, N):
        best = min(best, cost(p, R, C))

    result = best
    print("Case #%d: %s" % (case, result))