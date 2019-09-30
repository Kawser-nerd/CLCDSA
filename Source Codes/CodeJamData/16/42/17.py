#!/usr/bin/env python

import sys
ls = sys.stdin.readlines()[1:]

N = 0
PS = []

M = {}

def f(i, yes, no):
    key = (i, yes, no)
    if key in M:
        return M[key]
    if yes + no == 0:
        M[key] = 1.0
        return 1.0
    if i == len(PS):
        M[key] = 0.0
        return 0.0
    inc = 0.0
    if yes > 0:
        inc = PS[i] * f(i + 1, yes - 1, no)
    if no > 0:
        inc += (1.0 - PS[i]) * f(i + 1, yes, no - 1)
    M[key] = inc
    return inc

C = 1
while ls:
    N, k = [int(x) for x in ls[0].split()]
    p = [float(x) for x in ls[1].split()]
    ls = ls[2:]

    p.sort()
    ans = 0.0
    for i in range(k+1):
        PS = p[0:i] + p[len(p)-(k-i):]
        M.clear()
        ans = max(ans, f(0, k/2, k/2))

    print "Case #%d: %.8f" % (C, ans)
    C += 1
