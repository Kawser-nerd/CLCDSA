#!/usr/bin/env python
#coding: utf-8

from sys import stdin, stderr
from math import log10


def solve(R, C, N):
    if R == 1 or C == 1:
        L = R * C
        if L % 2 == 1:
            return max(N-L/2-1, 0) * 2
        else:
            if N <= L / 2:
                return 0
            else:
                return 1 + (N-L/2-1) * 2
    if (R * C) %  2 == 0:
        if N <= R * C / 2: return 0
        inner  = (R-2) * (C-2) / 2 # -4
        edge   = R + C - 4         # -3
        conner = 2                 # -2
    else:
        if N <= (R * C + 1) / 2:     return 0
        if N <= (R * C + 1) / 2 + 1: return 3
        inner  = ((R-2) * (C-2) + 1) / 2
        edge   = R + C - 6
        conner = 4
        pass
    ret = (R-1) * C + (C-1) * R
    n = R * C - N
    if n <= inner: return ret - n * 4
    ret -= inner * 4
    n -= inner
    if n <= edge: return ret - n * 3
    ret -= edge * 3
    n -= edge
    return ret - n * 2

T = int(stdin.readline())
for t in range(T):
    R, C, N = (int(wd) for wd in stdin.readline().split())
    print "Case #%i:" % (t+1),
    #print R, C, N,
    print solve(R, C, N)
