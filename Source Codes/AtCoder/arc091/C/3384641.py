#!/usr/bin/env python3

def solve(n, a, b):
    if a + b - 1 > n:
        return [ -1 ]
    if a * b < n:
        return [ -1 ]

    # construct in \omega^2
    xs = []
    xs += [ (0, - j) for j in range(b) ]
    for i in range(1, a):
        xs += [ (i, 0) ]
        j = 1
        while j < b and len(xs) + (a - i - 1) < n:
            xs += [ (i, - j) ]
            j += 1

    # coordinate compression
    f = {}
    for x in sorted(xs):
        k = len(f)
        f[x] = k
    return [ f[x] + 1 for x in xs ]


print(*solve(*map(int, input().split())))